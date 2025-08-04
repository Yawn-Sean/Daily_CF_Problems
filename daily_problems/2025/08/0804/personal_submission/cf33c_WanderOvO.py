"""
前后缀强制不相交，因为相交了就抵消了
相当于选中间一段不变的
设前缀和为 s[i]，则相当于最大化 -s[n] + 2 * (s[i] - s[j - 1])
其实就是找原本的一个最大的区间和
"""

n = int(input())
a = [0] + list(map(int, input().split()))
INF = int(1e18)
dp = [-INF for _ in range(n + 1)]
max_seg = 0
for i in range(1, n + 1):
    dp[i] = max(dp[i - 1] + a[i], a[i])
    max_seg = max(max_seg, dp[i])
s = 0
for i in range(1, n + 1):
    s += a[i]
print(2 * max_seg - s)
