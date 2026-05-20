import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
t=II()
for _ in range(t):
    n,p,x=MII()
    k=LII()
    k.sort(reverse=True)
    m=0
    sm=0
    for j in range(1,p+1):
        sm+=k[j-1]
        if j>x:
            diff=sm-n*x
            if diff >0:
                require=(diff+j-x-1)//(j-x)
                if require>m:
                    m=require
    print(m)