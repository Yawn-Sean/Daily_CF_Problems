# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-29 10:00:38
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
d = {}
ans = []


def my_swap(i: int, j: int):
    a[i - 1], a[j - 1] = a[j - 1], a[i - 1]
    ans.append((i, j))
    return


for i, x in enumerate(a):
    d[x] = i + 1
for i0, x in enumerate(a):
    i = i0 + 1
    j = d[i]
    if i == j:
        continue
    d[i] = i
    d[x] = j
    if abs(i - j) * 2 >= n:
        my_swap(i, j)
        continue
    if (i - 1) * 2 >= n:
        my_swap(i, 1)
        my_swap(1, j)
        my_swap(i, 1)
    elif (n - j) * 2 >= n:
        my_swap(i, n)
        my_swap(n, j)
        my_swap(i, n)
    else:
        my_swap(i, n)
        my_swap(n, 1)
        my_swap(1, j)
        my_swap(n, 1)
        my_swap(i, n)
print(len(ans))
for x in ans:
    print(*x)
