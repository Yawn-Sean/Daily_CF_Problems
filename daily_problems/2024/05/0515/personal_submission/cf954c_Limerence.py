# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-15 11:35:02
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

if n == 1:
    print("YES")
    print(a[0], 1)
    exit()
else:
    changes = {1}
    i = 1
    while i < n:
        if a[i] == a[i - 1]:
            print("NO")
            exit()
        changes.add(abs(a[i] - a[i - 1]))
        i += 1
        if len(changes) > 2:
            print("NO")
            exit()

if len(changes) == 1:
    print("YES")
    print(10**9, 1)
    exit()

mx = max(changes)
for i in range(1, n):
    x1, y1 = (a[i - 1] - 1) // mx, (mx if a[i - 1] % mx == 0 else a[i - 1] % mx)
    x2, y2 = (a[i] - 1) // mx, (mx if a[i] % mx == 0 else a[i] % mx)
    if abs(x1 - x2) + abs(y1 - y2) != 1:
        print("NO")
        exit()
print("YES")
print(10**9, mx)
