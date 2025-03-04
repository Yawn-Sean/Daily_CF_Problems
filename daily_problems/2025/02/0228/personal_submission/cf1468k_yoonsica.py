import sys
from collections import defaultdict
from itertools import pairwise
from math import comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1468/K
'''
for _ in range(RI()):
    a = RS()
    n = len(a)
    p = []
    sx = sy = 0
    for c in a:
        if c == 'L':
            sx -= 1
        elif c == 'R':
            sx += 1
        elif c == 'U':
            sy += 1
        else:
            sy -= 1
        p.append((sx, sy))
    
    
    for x, y in p:
        sx = sy = 0
        for c in a:
            if c == 'L':
                if sx - 1 != x or sy != y:
                    sx -= 1
            elif c == 'R':
                if sx + 1 != x or sy != y:
                    sx += 1
            elif c == 'U':
                if sy + 1 != y or sx != x:
                    sy += 1
            else:
                if sy - 1 != y or sx != x:
                    sy -= 1
        if sx == sy == 0:
            print(x, y)
            break
    else:
        print(0, 0)