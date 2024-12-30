import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right
from fractions import Fraction

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())


def mul(A, B, MOD):
    return [[sum(x * y % MOD for x, y in zip(A_row, B_col)) % MOD for B_col in zip(*B)] for A_row in A]

def qpow(matrix, n, MOD):
    C = [[1 if i == j else 0 for j in range(len(matrix))] for i in range(len(matrix))]
    base = matrix
    while n:
        if n & 1:
            result = mul(C, base, MOD)
        base = mul(base, base, MOD)
        n >>= 1
    return C

def calc1(n, MOD):
    if n == 1:
        return 0
    if n == 2:
        return 1 % MOD
    if n == 3:
        return 3 % MOD
    T = [[3, -1, -2], [1, 0, 0], [0, 1, 0]]
    initial = [3, 1, 0]
    T = qpow(T, n - 3, MOD)
    result = [sum(T[i][j] * initial[j] % MOD for j in range(len(initial))) % MOD for i in range(len(T))]
    return result[0] % MOD

def calc0(n, MOD):
    T = [[1, 1], [1, 0]]
    T = qpow(T, n + 1, MOD)
    return T[0][0] % MOD


def solve():
    n, k, l, m = MII()
    if k >= 1 << l or m == 1:
        output(0)
        return
    ans = 1


    for i in range(l):
        if k >> i & 1:
            ans *= calc1(n, m)
        else:
            ans *= calc0(n, m)
        ans %= m
    output(ans)


TC = 1

def main():
    for _ in range(TC):
        solve()

main()
