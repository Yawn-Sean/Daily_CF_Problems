import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
t=II()
for _ in range(t):
    m,n=MII()
    r1,c1,r2,c2=MII()
    a1=1 if (c2-c1)%2 else 2
    a2=1 if (r2-r1)%2 else 2
    if c2==c1:
        a1=0
    if r2==r1:
        a2=0
    print(a1+a2)
