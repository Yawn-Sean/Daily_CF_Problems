# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    mtx = []
    for i in range(1 << n):
        mtx.append(LI())

    prob = [[0 for _ in range(1 << n)] for _ in range(n + 1)]
    for j in range(1 << n):
        prob[0][j] = 1
    dp = [[0 for _ in range(1 << n)] for _ in range(n + 1)]
    # print(sum(prob[0]))

    for i in range(1, n + 1):
        for j1 in range(1 << n):
            for j2 in range(1 << n):

                if j1 != j2 and j1 // (1 << i) == j2 // (1 << i) and j1 // (1 << (i - 1)) != j2 // (1 << (i - 1)):
                    # print(i, j1, j2)
                    prob[i][j1] += prob[i - 1][j1] * prob[i - 1][j2] * mtx[j1][j2] / 100
                    dp[i][j1] = max(dp[i][j1], dp[i - 1][j2])

        # print(prob[i])
        # print(sum(prob[i]))

        for j1 in range(1 << n):
            dp[i][j1] += prob[i][j1] * (1 << (i - 1)) + dp[i - 1][j1]

    print(max(dp[n]))
