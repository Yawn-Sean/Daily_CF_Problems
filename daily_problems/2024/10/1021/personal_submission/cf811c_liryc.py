'''
https://codeforces.com/problemset/submission/811/287285541
CF 811C
20241021 Y2
1900
DP
'''
# ref

n = int(input())
a = list(map(int, input().split()))

lo = [0] * 5001
hi = [0] * 5001

for i in range(n - 1, -1, -1):
    lo[a[i]] = i

for i in range(n):
    hi[a[i]] = i

dp = [0] * (n + 1)
vis = [0] * 5001

for i in range(n):
    r = 0
    v = 0
    
    for j in range(i, n):
        if lo[a[j]] < i:
            break
        
        if not vis[a[j]]:
            vis[a[j]] = 1
            v ^= a[j]
        
        if hi[a[j]] > r:
            r = hi[a[j]]
        
        if j == r:
            dp[j + 1] = max(dp[j + 1], dp[i] + v)
    
    dp[i + 1] = max(dp[i + 1], dp[i])

    for j in range(5001):
        vis[j] = 0

print(dp[n])