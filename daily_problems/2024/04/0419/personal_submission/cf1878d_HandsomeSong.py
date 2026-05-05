import sys
input=sys.stdin.readline
def II(): return int(input())
def LII(): return list(map(int,input().split()))
def MII(): return map(int,input().split())
def I(): return input().strip()
t=II()
for _ in range(t):
    n,k=MII()
    s=I()
    ls=LII()
    rs=LII()
    for i in range(k):
        ls[i]-=1
        rs[i]-=1
    groups=[0]*n
    idx=0
    for i in range(k):
        while idx <= rs[i]:
            groups[idx]=i
            idx += 1
    q=II()
    pos=LII()
    for i in range(q):
        pos[i]-=1
    diff=[0] * (n + 1)
    for x in pos:
        g=groups[x]
        y=ls[g] + rs[g]-x
        if x>y:
            x,y=y,x
        diff[x]^=1
        diff[y + 1]^=1
    for i in range(n):
        diff[i + 1]^=diff[i]
    print(''.join(s[i] if diff[i] == 0 else s[ls[groups[i]] + rs[groups[i]]-i] for i in range(n)))
