# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
mod = 1000000007

tcn = 1
for _tcn_ in range(tcn):
    A, B, n, x = MI()
    if A == 1:
        y = x + n * B
        y %= mod
    else:
        y = pow(A, n, mod) * x + B * (pow(A, n, mod) - 1) * pow(A - 1, -1, mod)
        y %= mod
    print(y)
