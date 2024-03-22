import sys
input = lambda: sys.stdin.readline().strip()
n = int(input())
a = list(map(int, input().split()))
s_a = [-1] * (a[-1] + 1)
for i in range(n):
    s_a[a[i]] = i

dp = [1] * n
ans = 1
for i in range(n):
    for j in range(a[i]*2, a[-1]+1, a[i]):
        if s_a[j] != -1:
            dp[s_a[j]] = max(dp[s_a[j]], dp[i] + 1)
            ans = max(ans, dp[s_a[j]])
print(ans)
