/*
 *  sucaps.c
 *
 *  variant on sucap (from the libcap sources) which deals with linux
 *  2.4 kernels blatting capabilities on execve()
 *
 *  Copyright (c) 2002 Tim Deegan <tim.deegan@cl.cam.ac.uk>
 *  Based on a program by Finn Arne Gangstad <finnag@guardian.no>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id: sucaps.c,v 1.5 2005/10/17 09:36:54 tjd21 Exp $
 */
/*

CFS:en-48:faraday-two-slave [~]$ sudo chown root.root runcaps ; sudo chmod  6711 runcaps
CFS:en-48:faraday-two-slave [~]$ ./runcaps default default ./test_core_dump


self uid:2000 euid:0
caps before fork
The process 998 was given capabilities =ep
caps before changing UID
The process 998 was given capabilities =ep cap_setgid,cap_setuid,cap_sys_resource+i
./work/runcaps: child: could not set caps: Operation not permitted
test_core_dump: self uid:2000 euid:0
The process 998 was given capabilities =ep cap_setgid,cap_setuid,cap_sys_resource+i
test_core_dump: after self uid:2000 euid:2000
The process 998 was given capabilities =p cap_setgid,cap_setuid,cap_sys_resource+i
The process 998 was given capabilities =p cap_sys_resource+ei cap_setgid,cap_setuid+i
test_core_dump: final uid:2000 euid:2000
The process 998 was given capabilities =p cap_sys_resource+ei cap_setgid,cap_setuid+i
PR_GET_DUMPABLE returned 0
PR_SET_DUMPABLE returned 0
PR_GET_DUMPABLE returned 1
get RLIMIT_CORE returned:0 (cur:0 max:0)
set RLIMIT_CORE returned:0 errono:0
get RLIMIT_CORE ret:0 (cur:-1 max:-1) RLIM_INFINITY:-1
Segmentation fault (core dumped)

*/
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/capability.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <syslog.h>
#include <pthread.h>
#ifdef DEBUG
#define TRC(_s) fprintf(stderr, __FILE__ ":%i: %s\n", __LINE__, (_s));
#else
#define TRC(_s)
#endif

#define ROUNDUP(x,y)      ((((x)+(y)-1)/(y))*(y))

#define MAX_STRING_ARG_LEN 256
//#define MAX_CAPS_NUM 10
cap_value_t capList[] = { CAP_SYS_RESOURCE,  CAP_SYS_NICE, CAP_IPC_LOCK, \
                          CAP_NET_ADMIN, CAP_NET_BIND_SERVICE, CAP_NET_RAW, \
                          CAP_SYS_RAWIO };
unsigned num_caps = sizeof(capList) /sizeof(cap_value_t);

int logInit(const char *ident)
{
  openlog(ident, LOG_CONS | LOG_PERROR | LOG_PID, LOG_USER);
  //openlog(ident, LOG_CONS, LOG_USER);
  return 0;
}


char program_name[MAX_STRING_ARG_LEN];

void listCaps()
{
  cap_t caps = cap_get_proc();
  ssize_t y = 0;
  fprintf(stderr, "%s: pid:%d num of caps %d capabilities:%s\n",
          program_name, (int) getpid(),num_caps, cap_to_text(caps, &y));
  fflush(0);
  cap_free(caps);
}

int main (int argc, char **argv)
{
    //sample data
    cap_t cap, self_cap;
    cap_flag_value_t cval;
    uid_t uid;
    gid_t gid;
    pid_t pid;
    uid_t self_uid, self_euid;
    int pipefd[2], rv, status;

    //logInit("caps");

    char arg_user_name[MAX_STRING_ARG_LEN];
    char arg_group_name[MAX_STRING_ARG_LEN];


    if (argc < 1 || argv[argc] != NULL) {
       fprintf(stderr, "%s: arguments are not well formed\n", program_name);
       exit(1);
    }
    if (argc < 4) {
       fprintf(stderr,
              "usage: %s <caps> <user> <group> <program> [args...]\n",
              program_name);
       exit(1);
    }
    // setting pname ,uname, gname
    strncpy(program_name, argv[0], MAX_STRING_ARG_LEN);
    strncpy(arg_user_name, argv[1], MAX_STRING_ARG_LEN);
    strncpy(arg_group_name, argv[2], MAX_STRING_ARG_LEN);

    fprintf(stderr, "%s: user:%s group:%s\n", program_name, arg_user_name, arg_group_name);

    /* Get current UID, EUID */
    self_uid = getuid();
    self_euid = geteuid();
    //fprintf(stderr, "current uid:%d euid:%d\n", self_uid, self_euid);

    /* Check our own capabilities */
    self_cap = cap_get_proc();
    if (!self_cap)
    {
       fprintf(stderr, "%s: can't read my capset: %s\n",
              program_name, strerror(errno));
       exit(1);
    }

    //fprintf(stderr ,"caps beforehand : \n");
    //listCaps();
    /*
    if (cap_get_flag(self_cap, CAP_SETPCAP, CAP_EFFECTIVE, &cval) != 0) {
       fprintf(stderr, "%s: cap_get_flag() failed on valid data (how odd).\n",
              program_name);
       exit(1);
    }
    if (cval != CAP_SET) {
       fprintf(stderr, "%s: you need CAP_SETPCAP to use this program.\n",
              program_name);
       exit(1);
    }
    */
    //cap_free(self_cap);

    //listCaps();

    /* Read requested capabilities from the command line */
    /*
    cap = cap_from_text(argv[1]);
    if (!cap) {
       fprintf(stderr, "%s: Can't parse \"%s\".\n", program_name, argv[1]);
       exit(1);
    }
    */
    /* Convert username to uid */
    struct passwd *pw = getpwnam(arg_user_name);
    if (!pw) {
        fprintf(stderr, "%s: No such user: %s\n", program_name, arg_user_name);
        exit(1);
    }
    uid = pw->pw_uid;

    /* Convert groupname to gid */
    struct group *gr = getgrnam(arg_group_name);
    if (!gr) {
        fprintf(stderr, "%s: No such group: %s\n", program_name, arg_group_name);
        exit(1);
    }
    gid = gr->gr_gid;

    /* And now, the real work begins */
    /* Get rid of any supplemental groups */
    if (!getuid() && setgroups(0, NULL)) {
       fprintf(stderr, "%s: can't set groups: %s\n", program_name,
              strerror(errno));
        exit(2);
    }

    if (prctl(PR_SET_KEEPCAPS, 1) < 0){
        fprintf(stderr, "%s: prctl(PR_SET_KEEPCAPS) failed\n", program_name);
        exit (1);
    }

    /* updating all three sets */
    //cap_set_flag(self_cap, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
    cap_set_flag(self_cap, CAP_INHERITABLE, num_caps, capList, CAP_SET);
    cap_set_flag(self_cap, CAP_PERMITTED, num_caps, capList, CAP_SET);
    /* setting up ambient set with prctl */

    /* Setting up capabilities */
    /* applying changes in EPI set */
    if (cap_set_proc(self_cap) != 0)
    {
      fprintf(stderr, "unable to set capabilities: %s\n", strerror(errno));
      exit (1);
    }
    /*
     * This will add caps in ambient set which should retain
     * these caps after execvp system call and then we'll add
     * following caps in Effective set. As these caps will only
     * be persistent in Permitted and Inheritable ones.
     * */
   /* for(int i=0; i<num_caps; i++)*/
    /*{*/

      /*if(prctl(PR_CAP_AMBIENT, PR_CAP_AMBIENT_RAISE,(int) capList[i], 0, 0))*/
      /*{*/
        /*fprintf(stderr, "Cannot set cap %d , Index : %d" , (int) capList[i], i);*/
        /*exit(1);*/
      /*}*/
    /*}*/

    //fprintf(stderr, "caps before changing UID\n");
    //listCaps();

    /* Set gid and uid */
    if (setregid(gid, gid) != 0 || setreuid(uid, uid) != 0)
    {
       fprintf(stderr, "%s: parent: can't set uid/gid: %s.\n", program_name, strerror(errno));
        exit(2);
    }
    /*
    * These are ambient caps which would be "eip" after execvp call.
    */
    for(int i=0; i<num_caps; i++)
    {

      if(prctl(PR_CAP_AMBIENT, PR_CAP_AMBIENT_RAISE,(int) capList[i], 0, 0))
      {
        fprintf(stderr, "Cannot set cap %d , Index : %d" , (int) capList[i], i);
        exit(1);
      }
    }

    fprintf(stderr, "\ncaps after changing UID\n");
    /*
    cap_t curr_self_cap = cap_get_proc();
    cap_set_flag(curr_self_cap, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
    cap_set_flag(curr_self_cap, CAP_INHERITABLE, num_caps, capList, CAP_SET);
    cap_set_flag(curr_self_cap, CAP_PERMITTED, num_caps, capList, CAP_SET);
    cap_set_proc(curr_self_cap);*/
    listCaps();

    /* Fire up the victim */
    execvp(argv[3], argv + 3);

    /* Oops: not supposed to get this far */
    fprintf(stderr, "%s: parent: exec failed (%s): aborting.\n",
          program_name, strerror(errno));
    exit(2);
}
