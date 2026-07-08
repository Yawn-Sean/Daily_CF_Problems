import sys
input = sys.stdin.readline
def II():
    return int(input())
mx=10**5+2
mod=10**9+7
cnt=[0]*(mx)
for i in range(1,mx):
        for j in range(i*2,mx,i):
            cnt[j]+=1
for i in range(1,mx):
    cnt[i]+=cnt[i-1]
fact=[1]*(mx)
for i in range(1,mx):
    fact[i]=fact[i-1]*i%mod
t=II()
for _ in range(t):
    n=II()
    print(cnt[n]*pow(2,-1,mod)%mod*fact[n]%mod)