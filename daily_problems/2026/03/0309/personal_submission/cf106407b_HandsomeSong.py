import sys
input = sys.stdin.readline
def II():
    return int(input())
t=II()
mod=10**9+7
mxn=75
mxT=mxn*(mxn+1)//4
mxK=(mxn+2)//2
dp=[[0]*(mxK+1) for _ in range (mxT+1)]
dp[0][0]=1
fact=[1]*(mxn+2)
for i in range(1,mxn+2):
    fact[i]=(fact[i-1]*i)%mod
ans=[0]*(mxn+1)
for n in range(mxn+1):
    for s in range(mxT,n-1,-1):
        for c in range(mxK,0,-1):
            dp[s][c]+=dp[s-n][c-1]
            if dp[s][c]>=mod:
                dp[s][c]-=mod
    if n>=2:
        total=n*(n+1)//2
        if not total%2:
            tn=total//2
            kn=n//2+1
            sub=dp[tn][kn]
            ans[n]=(sub*fact[kn]%mod)*fact[n+1-kn]%mod

for _ in range(t):
    n=II()
    print(ans[n])
