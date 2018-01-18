"""
author : abhishek18620

"""
import math

def ii():
    return int(input())

def mi():
    return map(int, input().split())

def li():
    return list(mi())

def solve():
    l1=[]
    n=ii()
    for i in range(n):
        l2=list(mi())
        l2.sort()
        l1.append(l2)
    sol=0
    prvmax=0
    currmax=0
    for L in reversed(l1):
        currmax=max(L)
if __name__=="__main__":
    solve()
