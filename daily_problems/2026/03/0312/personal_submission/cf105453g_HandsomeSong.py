def MII():
    return map(int, input().split())
n,T=MII()
ts=[]
bs=[]
cc=0
for i in range(n):
    t,b,c=MII()
    cc+=c
    ts.append(t)
    bs.append(b-c)

dp=[0]*(n+1)
pt=0

for i in range(n):
    while ts[i]-ts[pt]>=T and pt+1<=i:
        pt+=1
    dp[i+1]=max(dp[i],dp[pt]+bs[i])
print(dp[n]+cc)
