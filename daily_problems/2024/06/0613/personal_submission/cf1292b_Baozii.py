import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right
from heapq import *
 
input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")
 
 
I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())
 
def dis(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)
 
 
def solve():
    x0, y0, ax, ay, bx, by = MII()
    xs, ys, t = MII()
    points = [[x0, y0]]
    for _ in range(60):
        x, y = points[-1]
        nx, ny = ax * x + bx, ay * y + by
        points.append([nx, ny])
    ans = 0
    for i in range(len(points)):
        if dis(xs, ys, *points[i]) > t:
            continue
        temp = t - dis(xs, ys, *points[i])
        j = i
        while j + 1 < len(points):
            if (d := dis(*points[j], *points[j + 1])) <= temp:
                temp -= d
                j += 1
            else:
                break
        ans = max(ans, j - i + 1)
        j = i
        temp = t - dis(xs, ys, *points[i])
        while j - 1 >= 0:
            if (d := dis(*points[j], *points[j - 1])) <= temp:
                temp -= d
                j -= 1
            else:
                break
        ans = max(ans, i - j + 1)
    output(ans)
 
TC = 1
 
def main():
    for _ in range(TC):
        solve()
 
main()
