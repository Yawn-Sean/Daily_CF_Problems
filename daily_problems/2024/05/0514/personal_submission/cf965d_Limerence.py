# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-14 11:42:42
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


from itertools import accumulate

w, l = invr()
a = inlt()
pre_sum = [0] + list(accumulate(a))
mn = 0x3F3F3F3F
for i in range(l, w):
    if pre_sum[i] - pre_sum[i - l] < mn:
        mn = pre_sum[i] - pre_sum[i - l]
print(mn)
