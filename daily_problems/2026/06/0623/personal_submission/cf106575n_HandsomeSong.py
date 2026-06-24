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
    n,ca,cb=MII()
    a=LII()    
    b=LII()
    pos_b={b[i]: i for i in range(n)}
    suf=[10**18]*(2*n+2)
    for v in range(2*n,0,-1):
        suf[v]=suf[v+1]
        if v in pos_b:
            suf[v]=min(suf[v],cb*pos_b[v])
    ans=min(ca*i+suf[a[i]+1] for i in range(n))
    print(ans)