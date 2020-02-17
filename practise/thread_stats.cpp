/*
 * compilation
 * g++ -O2 -std=c++14 -Wall -Wextra -Wfatal-errors -w -o stats thread_stats.cpp
 * -lcurl -lpthread
 *  ./stats <num_of_thread>
 */

#include <cerrno>
#include <chrono>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <vector>

// linux includes
#include <curl/curl.h>
#include <experimental/filesystem>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/types.h>

#define trace2(x, y) std::cerr << __func__ << " : " << #x << ": " << x << " | " << #y << ": " << y << std::endl;
#define trace3(x, y, z)                                                                                                \
  std::cerr << __func__ << " : " << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z            \
            << std::endl;
#define trace4(a, b, c, d)                                                                                             \
  std::cerr << __func__ << " : " << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "   \
            << #d << ": " << d << std::endl;
#define trace5(a, b, c, d, e)                                                                                          \
  std::cerr << __func__ << " : " << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "   \
            << #d << ": " << d << " | " << #e << ": " << e << std::endl;

namespace fs = std::experimental::filesystem;

void CheckIfExist(const std::string& path) {
  printf("%s: %s %s\n", __func__, path.c_str(), fs::exists(path) ? "exists" : "does not exist");
}

void ListThreads(pid_t pid) {
  std::string pid_str = std::to_string(pid);
  std::string path    = "/proc/" + pid_str + "/task";
  printf("%s: path = %s\n", __func__, path.c_str());
  for (const auto& entry : fs::directory_iterator(path)) {
    printf("%s  ", entry.path().c_str());
  }
  printf("\n");
  return;
}

void GetThreadStats() {
  struct rusage thread_usage;
  if (getrusage(RUSAGE_THREAD, &thread_usage) == -1) {
    printf("%s: Failed to getusage stats Error: %s", __func__, std::strerror(errno));
    return;
  }
  ListThreads(getpid());
  pid_t tid = syscall(SYS_gettid);
  CheckIfExist("/proc/" + std::to_string(tid) + "/");
  printf("tid = %d\ncpu-time = %d\nsystem-time = %d\nresident_size = %ld\npage-faults = %ld\n", (int)tid,
         (int)thread_usage.ru_utime.tv_usec, (int)thread_usage.ru_stime.tv_usec, thread_usage.ru_maxrss,
         thread_usage.ru_majflt);
}

void TestConnection(std::vector<std::string>& url_list, int start, int end) {
  trace2(start, end);
  CURL* curl;
  int   res = 0;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
  std::string url;
  for (int i = start; i <= end; i++) {
    url = url_list[i];
    printf("testing %s\n", url.c_str());
    if (url.length() == 0) {
      return;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    res = curl_easy_perform(curl);
    if (!res) {
      std::cout << " URL : " << url << " is working"
                << " thread id = " << std::this_thread::get_id() << std::endl;
      GetThreadStats();
    } else
      std::cout << " URL : " << url << " is not working"
                << " thread id = " << std::this_thread::get_id() << std::endl;
  }
  curl_easy_cleanup(curl);
  curl_global_cleanup();
}

void Solve(std::vector<std::string> url_list, const int& num_of_threads) {
  printf("%s: num_of_threads = %d\n", __func__, num_of_threads);
  std::vector<std::thread> threadpool;
  int                      partition = url_list.size() / num_of_threads;
  int                      ind1      = 0;
  int                      ind2      = partition - 1;
  for (int i = 0; i < num_of_threads; i++) {
    trace2(ind1, ind2);
    threadpool.emplace_back(std::thread(TestConnection, std::ref(url_list), ind1, ind2));
    ind1 = ind2 + 1;
    ind2 = (i == 6) ? url_list.size() - 1 : ind1 + partition - 1;
  }
  for (auto& thread : threadpool) {
    thread.join();
  }
}

int main(int argc, char** argv) {
  freopen("websites.txt", "rt", stdin);
  std::string              url;
  std::vector<std::string> url_list;
  while (std::getline(std::cin, url)) {
    // printf("'%s  '", url.c_str());
    url_list.emplace_back(url);
  }
  int num_of_threads;
  int num_of_times;
  if (argc > 2) {
    num_of_threads = *argv[1] - 48;
    num_of_times   = *argv[2] - 48;
  } else {
    printf("Error: number of threads is missing ../stats <num_of_threads> <number_of_times>\n");
    return 0;
  }
  printf("\n");
  printf("%s: url list size = %d\n", __func__, (int)url_list.size());
  int iteration = 0;
  while (++iteration <= num_of_times) {
    printf("iteration %d\n", iteration);
    Solve(url_list, num_of_threads);
  }
  return 0;
}

