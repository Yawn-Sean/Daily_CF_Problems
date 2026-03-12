# -*- coding: UTF-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
INF = 10**6


if __name__ == "__main__":
    n = int(input())
    a = [list(map(int, input().split())) for _ in range(n)]

    cost = [a[i][i] for i in range(n)]
    ans = 0
    for _ in range(n):
        p = min(range(n), key=lambda x: cost[x])
        ans += cost[p]
        cost[p] = INF
        for i in range(n):
            if cost[i] != INF and a[p][i] < cost[i]:
                cost[i] = a[p][i]

    print(ans)
