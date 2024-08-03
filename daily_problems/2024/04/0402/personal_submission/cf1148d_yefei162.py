# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
nums = [LGMI() for _ in range(n)]
up = []
down = []
for i in range(n):
    a, b = nums[i]
    if a < b:
        up.append(i)
    else:
        down.append(i)
up.sort(key=lambda x: -nums[x][1])
down.sort(key=lambda x: nums[x][1])
if len(up) > len(down):
    print(len(up))
    print(*[i+1 for i in up])
else:
    print(len(down))
    print(*[i+1 for i in down])
