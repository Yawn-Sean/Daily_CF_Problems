import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log
from itertools import combinations, permutations

def solve():
    n = int(input())
    p = [0] + list(map(int, input().split()))

    vis = [0] * (n + 1)
    ans = 0
    tmp = []

    for i in range(1, n + 1):
        if vis[i]:
            continue

        cur = [i]
        while p[cur[-1]] != i:
            cur.append(p[cur[-1]])

        for x in cur:
            vis[x] = 1

        l = len(cur)

        if l % 2 == 0:
            v = 0
            for j in range(l):
                if j & 1:
                    v += cur[j]
                else:
                    v -= cur[j]
            ans += abs(v)
        else:
            v = 0
            for j in range(1, l):
                if j & 1:
                    v += cur[j]
                else:
                    v -= cur[j]

            res = 0
            for j in range(l):
                if j & 1:
                    res = max(res, cur[j] + v)
                    v += cur[(j + 1) % l]
                    v -= cur[j]
                else:
                    res = max(res, cur[j] - v)
                    v -= cur[(j + 1) % l]
                    v += cur[j]

            tmp.append(res)

    tmp.sort(reverse=True)

    for i, x in enumerate(tmp):
        if i & 1:
            ans -= x
        else:
            ans += x

    print(ans)

T = int(input())
for _ in range(T):
    solve()
