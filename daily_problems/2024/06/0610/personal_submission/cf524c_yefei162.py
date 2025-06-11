# -*- coding : utf-8 -*-
import sys
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())


n, m = MI()
A = LI()
q = I()
queries = [I() for _ in range(q)]
hst = defaultdict(lambda: m + 1)

for a in A:
    for c in range(1, m + 1):
        hst[a * c] = min(hst[a * c], c)

for x in queries:
    ans = m + 1
    for k, v in hst.items():
        if x == k:
            ans = min(ans, hst[k])
        elif k < x and x - k in hst:
            ans = min(ans, hst[x - k] + v)
    if ans <= m:
        print(ans)
    else:
        print(-1)