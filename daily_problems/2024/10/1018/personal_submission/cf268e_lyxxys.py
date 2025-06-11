import bisect
import collections
import heapq
import sys
import typing
import math
from functools import cmp_to_key

input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    A = [0]*n
    prob = [0]*n
    for i in range(n):
        A[i], prob[i] = map(int, input().split())

    def cmps(a, b):
        v1 = A[a] * prob[a] * (100 - prob[b])
        v2 = A[b] * prob[b] * (100 - prob[a])
        if v1 < v2: return 1
        elif v1 > v2: return -1
        else: return 0

    p = sorted(range(n), key = cmp_to_key(cmps))
    ans, cur = 0, 0
    for i in p:
        ans += cur * (100 - prob[i])/100 + A[i]
        cur += A[i] * prob[i] / 100

    print(ans)
