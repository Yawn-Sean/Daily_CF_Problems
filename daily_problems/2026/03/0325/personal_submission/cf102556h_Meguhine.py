# -*- coding: UTF-8 -*-
from collections import deque
from sys import exit
from typing import List

M = int(input())

X = M
x = 2
ps = []
cs = []
while x * x <= X:
    if X % x == 0:
        ps.append(x)
        cc = 0
        while X % x == 0:
            X //= x
            cc += 1
        cs.append(cc)
    x += 1
if X != 1:
    ps.append(X)
    cs.append(1)


def check(u: List[int]) -> int:
    cc = 1
    for c in u:
        cc *= (c + 1)
    x, res = 1, 1
    for p, c in zip(ps, u):
        tmp = pow(p, c * (c + 1) // 2)
        if res * tmp > M:
            return -1
        res *= pow(tmp, cc // (c + 1))
        if res > M:
            return -1
        x *= pow(p, c)
    if res > M:
        return -1
    return x if res == M else 0


n = len(ps)
u = [1] * n
x = check(u)
if x > 0:
    print(x)
    exit(0)

p = deque([u])
vis = set()
while p:
    u = p.popleft()
    for i in range(n):
        v = u.copy()
        v[i] += 1
        h = hash(tuple(v))
        if h in vis:
            continue
        x = check(v)
        if x > 0:
            print(x)
            exit(0)
        if x == 0:
            vis.add(h)
            p.append(v)
print("-1")
