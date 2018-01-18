"""
author : abhishek18620

"""
#import pdb
def ii():
    return int(input())

def mi():
    return map(int, input().split())

def li():
    return list(mi())

def util(N,kind):
    max_so_far =a[0]
    curr_max = a[0]
    lst=N
    if kind:
        lst=N+N
    for i in range(1,lst):
        ind=i
        if kind:
            ind=i%N
        curr_max = max(a[ind], curr_max + a[ind])
        max_so_far = max(max_so_far,curr_max)
    return max_so_far

a=[]
for t in range(ii()):
    N,K = mi()
    a = li()
    arrsum=0
    ans=0
    #pdb.set_trace()
    for num in a:
        arrsum=arrsum+num
    if arrsum>0:
        if K>2:
            first=0
            temp=0
            for num in reversed(a):
                temp=temp+num
                first=max(temp,first)
            temp=0
            second=0
            for num in a:
                temp=temp+num
                second=max(temp,second)
            #print(util(N,1))
            #print(util(N,0))
            ans=max(util(N,1),first+(K-2)*arrsum+second)
            ans=max(util(N,1),first+(K-2)*arrsum+second)
        elif K==2:
            ans=util(N,1)
        else:
            ans=util(N,0)
    else:
        if K>=2:
            ans=util(N,1)
        else:
            ans=util(N,0)
    print(ans)
    a.clear()
