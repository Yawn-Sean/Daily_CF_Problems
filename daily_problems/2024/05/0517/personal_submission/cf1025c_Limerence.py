# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-17 10:35:17
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


s = ins()
n = len(s)
s += s
cnt = mx = 1
for i in range(1, 2 * n):
    if s[i] == s[i - 1]:
        if cnt > mx:
            mx = cnt
        cnt = 1
    else:
        cnt += 1
if cnt > mx:
    mx = cnt
print(min(mx, n))
