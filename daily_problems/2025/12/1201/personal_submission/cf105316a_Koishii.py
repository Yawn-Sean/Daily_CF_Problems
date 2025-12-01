import sys
from itertools import accumulate
input = lambda: sys.stdin.readline().rstrip()

mod = 10 ** 9 + 7

def soviet():
    n = int(input())
    a = list(map(int, input().split()))
    a = [0] + list(accumulate(a))
    
    sum = a[n] - 1 >> 1
    dp = [0] * (n + 1)
    dp[0] = 1

    l = 0
    tot = 1
    for i in range(1, n + 1):
        while a[i] - a[l] > sum:
            tot = (tot - dp[l]) % mod
            l += 1
        dp[i] = tot
        tot = (tot + dp[i]) % mod

    print(dp[n])

soviet()
