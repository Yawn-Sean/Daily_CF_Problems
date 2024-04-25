# -*- coding: utf-8 -*-
# @Time: 2024/4/24 11:24
# @Author: yfwang
# @File: cf749d_yefei162.py

import bisect
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
bids = [LI() for _ in range(n)]
q = I()
queries = [LI() for _ in range(q)]

groups = [[] for _ in range(n + 1)]
for a, b in bids:
    groups[a].append(b)

mxab = []
for a, group in enumerate(groups):
    if group:
        mxab.append([a, group[-1]])

mxab.sort(key=lambda x: -x[1])

for query in queries:
    st = set(query[1:])
    person, price = 0, 0
    for i in range(len(mxab)):
        a, v = mxab[i]
        if a in st:
            continue
        else:
            person = a
            while i + 1 < len(mxab) and mxab[i+1][0] in st:
                i += 1

            if i + 1 < len(mxab):
                mx = mxab[i+1][1]
                j = bisect.bisect_left(groups[person], mx)
                price = groups[person][j]
            else:
                price = groups[person][0]
            break
    print(person, price)
