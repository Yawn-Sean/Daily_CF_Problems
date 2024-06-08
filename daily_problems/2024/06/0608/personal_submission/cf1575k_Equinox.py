import math
import random
import sys
from functools import reduce
from sortedcontainers import SortedList

sys.stdin = open('in.txt', 'r')

N, M, K, R, C = map(int, input().split())

ax, ay, bx, by = map(int, input().split())

if ax == bx and ay == by:
    print(pow(K, N * M, 10**9 + 7))
else:
    print(pow(K, N * M - R * C, 10**9 + 7))
