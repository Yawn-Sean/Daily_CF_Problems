from collections import Counter
mod=998244353
n=int(input())
a=list(map(int,input().split()))
cnt=Counter()
for i in range(n):
    cnt[a[i]]=i
l=[0]*n
for i in range(n):
    l[i]=cnt[a[i]]
i=-1
ans=0
while i<n-1:
    i+=1
    ans+=1
    t=l[i]
    while i<n-1 and i<t:
        i+=1
        if l[i]>t:
            t=l[i]
if True:
    dp = [0] * ans
    dp[0] = 1
    for i in range(1, ans):
        dp[i] = 2 * dp[i-1]
        dp[i] %= mod
    print(dp[-1])
