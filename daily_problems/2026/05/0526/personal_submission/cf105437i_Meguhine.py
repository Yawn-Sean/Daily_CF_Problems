import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
a = list(map(int, input().split()))

cur = 0
dp = array('i', [0] * (m + 1))
d = array('i', [0] * (m + 2))

for r in a:
    if r == 0:
        for i in range(1, cur + 1):
            d[i] += d[i - 1]
        for i in range(cur + 1):
            dp[i] += d[i]
        cur += 1
        for i in range(cur, 0, -1):
            dp[i] = max(dp[i], dp[i - 1])
        d = array('i', [0] * (m + 2))
    elif r > 0:
        d[r] += 1
    else:
        # cur - x >= -r
        # x <= cur + r
        x = cur + r
        if x >= 0:
            d[0] += 1
            d[x + 1] -= 1

for i in range(1, cur + 1):
    d[i] += d[i - 1]
for i in range(cur + 1):
    dp[i] += d[i]
print(max(dp))
