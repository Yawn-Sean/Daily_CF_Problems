# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(GMI())

n, q = MI()
ops = [LGMI() for _ in range(q)]
ans = 0

for idx in range(q):
    diff = [0] * (n + 1)
    for i in range(q):
        if i == idx:
            continue
        l, r = ops[i]
        diff[l] += 1
        diff[r + 1] -= 1
    acc = [0] * n
    acc[0] = diff[0]
    for i in range(1, n):
        acc[i] = acc[i - 1] + diff[i]

    tot = 0
    cnt_one = [0] * (n + 1)
    for i in range(n):
        cnt_one[i + 1] = cnt_one[i] + int(acc[i] == 1)
        tot += int(acc[i] > 0)
    for i in range(q):
        if i == idx:
            continue
        l, r = ops[i]
        x = cnt_one[r + 1] - cnt_one[l]
        ans = max(ans, tot - x)
print(ans)
