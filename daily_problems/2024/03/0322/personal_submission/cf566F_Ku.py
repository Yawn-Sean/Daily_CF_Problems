from collections import Counter
n = int(input())
a = list(map(int,input().split()))
cnt = Counter(a)
dp = [0] * (10 ** 6 + 1)
for i in range(1,10**6 + 1):
    dp[i] += cnt[i]
    for j in range(i,10**6 + 1,i):
        dp[j] = max(dp[i],dp[j])
print(max(dp))
