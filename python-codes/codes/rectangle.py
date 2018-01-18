"""
author : abhishek18620

"""

def ii():
    return int(input())

def mi():
    return map(int, input().split())

def li():
    return list(mi())

def solve():
    for t in range(int(input())):
        a,b,c,d=mi()
        ans=False
        if a==b==c==d:
            ans=True
        elif a==b and c==d:
            ans=True
        elif a==d and c==b:
            ans=True
        elif a==c and d==b:
            ans=True
        if ans:
            print("YES")
        else:
            print("NO")
if __name__=="__main__":
    solve()
