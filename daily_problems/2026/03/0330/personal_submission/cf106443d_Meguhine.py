import sys
from array import array

N = 5 * 10**5 + 5
dp = array('b', [0] * N)
dp[1] = dp[3] = dp[4] = dp[5] = 1
l, c = 1, 4
for x in range(7, N):
    y = (x + 1) // 2
    L = x - y
    while l < L:
        c -= dp[l]
        l += 1
    dp[x] = (c != x - L)
    c += dp[x]


it = map(int, sys.stdin.buffer.read().split())
next(it)
print('\n'.join("mastermei" if dp[x] else "the greatest" for x in it))
