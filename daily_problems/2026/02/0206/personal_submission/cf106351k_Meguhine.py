import math
import array
import bisect
import collections
import typing
from typing import *

M = 10**5 + 1
factors = [[] for _ in range(M)]

for i in range(1, M):
    for j in range(i, M, i):
        factors[j].append(i)

if __name__ == "__main__":
    n, mn, mx = map(int, input().split())
    a = list(map(int, input().split()))

    cnt = [0] * M
    for x in a:
        cnt[x] += 1

    ans = 0
    for l in range(mn, mx + 1):
        ans += cnt[l] * (cnt[l] - 1) // 2
        for i, x in enumerate(factors[l]):
            for j in range(i):
                y = factors[l][j]
                g = math.gcd(x, y)
                if (g >= mn and x * y == g * l):
                    ans += cnt[x] * cnt[y]
    print(ans)
