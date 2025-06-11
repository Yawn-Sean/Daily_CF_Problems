import sys
from math import *
from bisect import *
from heapq import *
from collections import Counter
from itertools import accumulate
from sortedcontainers import SortedList
sys.stdin = open('in.txt', 'r')
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
I = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 998244353

'''
    (ai - bi) * j - ai + bi * n
'''

def solve() -> None:
    n = I()
    ab = list(list(MII()) for _ in range(n))
    ab.sort(key=lambda x: x[1] - x[0])
    print(sum([a * i + b * (n - i - 1) for i, (a, b) in enumerate(ab)]))
# T = I()
# for _ in range(T):
solve()