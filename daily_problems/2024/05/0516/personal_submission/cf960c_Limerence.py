# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-16 11:25:03
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


X, d = invr()
start = len(bin(X + 1)) + 1
ans = []
cur = 1
for i in range(start, 0, -1):
    while X >= 2**i - 1:
        X -= 2**i - 1
        ans.extend([cur] * i)
        cur += d
print(len(ans))
print(*ans)
