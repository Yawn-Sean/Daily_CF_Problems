# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-06-08 16:38:25
# ----------------------------------------------

import sys

input = sys.stdin.readline


def inp():
    return int(input())


def inlt():
    return list(map(int, input().split()))


def insr():
    s = input()
    return list(s[: len(s) - 1])


def invr():
    return map(int, input().split())


def ins():
    return input().strip()


def solve():
    n, m = invr()
    candidate = []
    for i in range(min(m, n + 1)):
        for j in range(min(m, n + 1)):
            if (i**2 + j**2) % m == 0:
                candidate.append((i, j))
    ans = 0
    for ii, jj in candidate:
        row_n = n // m + ((n % m) >= ii and ii != 0)
        col_n = n // m + ((n % m) >= jj and jj != 0)
        ans += row_n * col_n
    return ans


t = 1
while t:
    t -= 1
    print(solve())
