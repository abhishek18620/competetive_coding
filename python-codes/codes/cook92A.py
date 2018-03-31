"""
Author : abhishek18620
Date : 2018-03-24
File : cook92A

"""
import bisect as bs

def ii():
    return int(input())

def mi():
    return map(int, input().split())

def li():
    return list(mi())

a=[]
def solve():
    t=ii()
    #print("test = "+repr(t))
    for tc in range(t):
        x=ii()
        lob=bs.bisect_left(a,x)
        upb=bs.bisect_right(a,x)
        #print("lob = {0} and upb = {1} and x={2}".format(lob,upb,x))
        if(a[lob]==x):
            print(lob)
        elif x-a[lob-1]>a[upb]-x:
            print(upb+a[upb]-x)
        elif x-a[lob-1]<=a[upb]-x:
            print(lob-1+x-a[lob-1])
if __name__=="__main__":
    num=0
    a.append(num)
    while a[-1]<=10**9:
        num=num+1
        a.append(a[-1]+num)
    solve()
