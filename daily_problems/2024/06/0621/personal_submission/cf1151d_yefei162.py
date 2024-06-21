# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    C = []
    tot = 0
    for i in range(n):
        a, b = MI()
        tot += b * n - a
        C.append(a - b)
    C.sort(reverse=True)
    for i, c in enumerate(C, start=1):
        tot += c * i
    print(tot)
