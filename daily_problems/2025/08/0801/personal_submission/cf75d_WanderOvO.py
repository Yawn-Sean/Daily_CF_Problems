"""
对每个小数列，求整个数列的和 s，前缀最大和 max_pre，后缀最大和 max_suf，小数列自己的最大连续子段和 max_s
如何求整个数列的最大连续子段和？
- 不允许选空段
- 如果最大连续子段不跨小数列，那么答案就是某个小数列的最大连续子段和
- 如果最大连续子段跨数列，那么其中间可能有若干个完整的小数列（可能是 0 个）
  - 对于 0 个完整数列的情况，其实就是前一个的最大后缀 + 后一个的最大前缀
  - 对于 >= 1 个完整数列的情况，钦定子段中最后一个完整的数列为 i，这个数列的序号是 id[i]，且后边不再选下一段的前缀了，最大和为 dp[i]
    - 前面不选完整数列了，则 dp[i] = max(dp[i], s[id[i]] + max(0, max_suf[id[i - 1]]))
    - 前面还选完整数列，则 dp[i] = max(dp[i], s[id[i]] + max(0, dp[i - 1]))
    - 算出所有 dp[i] 之后，看看和 i + 1 的前缀拼接是否会更好，更好则拼接，否则就算了
"""

n, m = map(int, input().split())
INF = int(1e18)
s = [0 for _ in range(n + 1)]
max_pre = [-INF for _ in range(n + 1)]
max_suf = [-INF for _ in range(n + 1)]
max_s = [-INF for _ in range(n + 1)]

for i in range(1, n + 1):
    a = list(map(int, input().split()))
    cnt = a[0]
    for j in range(1, cnt + 1):
        s[i] += a[j]
        max_pre[i] = max(max_pre[i], s[i])
    val = 0
    for j in range(cnt, 0, -1):
        val += a[j]
        max_suf[i] = max(max_suf[i], val)
    dp = [-INF for _ in range(cnt + 1)]
    dp[0] = 0
    for j in range(1, cnt + 1):
        dp[j] = max(a[j], a[j] + dp[j - 1])
        max_s[i] = max(max_s[i], dp[j])

id = [0] + list(map(int, input().split()))
dp = [-INF for _ in range(m + 1)]

res = -INF
for i in range(1, m + 1):
    res = max(res, max_s[id[i]])
    if i + 1 <= m:
        res = max(res, max_suf[id[i]] + max_pre[id[i + 1]])

dp[1] = s[id[1]]
for i in range(2, m + 1):
    dp[i] = max(dp[i], s[id[i]] + max(0, max_suf[id[i - 1]]))
    dp[i] = max(dp[i], s[id[i]] + max(0, dp[i - 1]))

for i in range(1, m + 1):
    res = max(res, dp[i])
    if i + 1 <= m:
        res = max(res, dp[i] + max(0, max_pre[id[i + 1]]))

print(res)
