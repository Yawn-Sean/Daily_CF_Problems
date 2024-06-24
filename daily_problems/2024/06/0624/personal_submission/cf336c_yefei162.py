# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())

n = I()
A = LI()
ans = []
for v in range(31, -1, -1):
    ans = []
    x = (1 << (v + 1)) - 1
    for a in A:
        if a >> v & 1 == 0:
            continue
        x = x & a
        ans.append(a)
    if x == (1 << v):
        break

print(len(ans))
print(*ans)
