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
        n=ii()
        s=input().strip()
        tot=0
        for num in s:
            num_str=str(num)
            for ch in num_str.split():
                tot=tot+int(ch)
        if tot%3==0:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    solve()
