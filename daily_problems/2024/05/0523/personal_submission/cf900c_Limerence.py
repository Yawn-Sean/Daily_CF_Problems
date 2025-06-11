# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-23 18:07:11
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


n = inp()
a = inlt()
fir, sec = -1, -1
change = [0] * n  # if delete i + 1, the change of the answer is change[i]
for x in a:
    if x > fir:
        fir, sec = x, fir
        change[x - 1] -= 1
    elif x > sec:
        sec = x
        change[fir - 1] += 1
mx = max(change)
for i in range(n):
    if change[i] == mx:
        print(i + 1)
        break
