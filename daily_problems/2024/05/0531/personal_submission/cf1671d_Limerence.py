# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-31 11:50:26
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
    a = inlt()
    ans = 0
    for i in range(n - 1):
        ans += abs(a[i] - a[i + 1])
    mx, mn = max(a), min(a)
    if mn == 1:
        if mx >= m:
            return ans
        else:
            mn_delta = float("inf")
            for i in range(n - 1):
                mn_delta = min(
                    mn_delta, abs(a[i] - m) + abs(a[i + 1] - m) - abs(a[i] - a[i + 1])
                )
            mn_delta = min(mn_delta, abs(a[0] - m), abs(a[-1] - m))
            return ans + mn_delta
    else:
        if mx >= m:
            mn_delta = float("inf")
            for i in range(n - 1):
                mn_delta = min(
                    mn_delta, abs(a[i] - 1) + abs(a[i + 1] - 1) - abs(a[i] - a[i + 1])
                )
            mn_delta = min(mn_delta, abs(a[0] - 1), abs(a[-1] - 1))
            return ans + mn_delta
        else:
            mn_pair_1 = -2, -2
            mn_pair_m = -2, -2
            mn_delta_1 = float("inf")
            mn_delta_m = float("inf")
            for i in range(n - 1):
                if (
                    abs(a[i] - 1) + abs(a[i + 1] - 1) - abs(a[i] - a[i + 1])
                    < mn_delta_1
                ):
                    mn_delta_1 = (
                        abs(a[i] - 1) + abs(a[i + 1] - 1) - abs(a[i] - a[i + 1])
                    )
                    mn_pair_1 = i, i + 1
                if (
                    abs(a[i] - m) + abs(a[i + 1] - m) - abs(a[i] - a[i + 1])
                    < mn_delta_m
                ):
                    mn_delta_m = (
                        abs(a[i] - m) + abs(a[i + 1] - m) - abs(a[i] - a[i + 1])
                    )
                    mn_pair_m = i, i + 1
            if abs(a[0] - 1) <= mn_delta_1:
                mn_delta_1 = abs(a[0] - 1)
                mn_pair_1 = -1, 0
            if abs(a[-1] - 1) < mn_delta_1:
                mn_delta_1 = abs(a[-1] - 1)
                mn_pair_1 = n - 1, -1
            if abs(a[0] - m) < mn_delta_m:
                mn_delta_m = abs(a[0] - m)
                mn_pair_m = -1, 0
            if abs(a[-1] - m) <= mn_delta_m:
                mn_delta_m = abs(a[-1] - m)
                mn_pair_m = n - 1, -1
            if mn_pair_1 != mn_pair_m:
                return ans + mn_delta_1 + mn_delta_m
            else:
                mn1, mx1 = min(a[mn_pair_1[0]], a[mn_pair_1[1]]), max(
                    a[mn_pair_1[0]], a[mn_pair_1[1]]
                )
                delta = abs(mn1 - 1) + abs(mx1 - m) + (m - 1) - (mx1 - mn1)
                return ans + delta


t = inp()
while t:
    t -= 1
    print(solve())
