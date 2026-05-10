import sys
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
mod=10**9+7
MAX_N=2*10**6+5
fact=[1]*MAX_N
for i in range(1,MAX_N):
    fact[i]=fact[i-1]*i%mod
def C(n,k):
    if k<0 or k>n:
        return 0
    return fact[n]*pow(fact[k],mod-2,mod)%mod*pow(fact[n-k],mod-2,mod)%mod
t=II()
for _ in range(t):
    b,g,x,y=MII()
    if x+y>g:
        print(0)
    else:
        total=C(b+g,g)
        bad=C(b+x+y-1,x+y-1)
        print((total-bad+mod)%mod)