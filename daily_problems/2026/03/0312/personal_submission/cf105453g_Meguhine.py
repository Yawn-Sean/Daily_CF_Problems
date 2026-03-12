# -*- coding: UTF-8 -*-
import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
INF = 2 * 10**9

if __name__ == "__main__":
    n, dt = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    pre = list(accumulate(
        range(n),
        lambda acc, i: acc + a[i][2],
        initial=0
    ))

    # dp[i], a[0~i], max profit
    dp = [a[0][1]] + [pre[i] + a[i][1] for i in range(1, n)]

    k = 0
    for i in range(1, n):
        while k < i and a[i][0] - a[k][0] >= dt:
            k += 1

        if k:
            res = dp[k - 1] + pre[i] - pre[k] + a[i][1]
            if dp[i] < res:
                dp[i] = res

        res = dp[i - 1] + a[i][2]
        if dp[i] < res:
            dp[i] = res

    print(dp[n - 1])
