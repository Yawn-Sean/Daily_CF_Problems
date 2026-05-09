import sys
input = sys.stdin.readline
def II():
    return int(input())
t=II()
mod=10**9+7
mx=150005
fact=[1]*mx
for i in range(1,mx):
    fact[i]=(fact[i-1]*i)%mod
inv2=(mod+1)//2
for _ in range(t):
    n=II()
    o=(n+1)//2
    e=n//2
    ans=(fact[o+1]*fact[o])%mod
    if n%2:
        ans=(ans*inv2)%mod
    print(ans)