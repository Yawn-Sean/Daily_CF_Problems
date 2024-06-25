# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()

s = input()
n = len(s)
tot = 0
for i in range(n):
    a, b = 0, 0
    for j in range(i, n):
        if s[j] == '(':
            a += 1
        elif s[j] == ')':
            a -= 1
        else:
            b += 1
        if a + b < 0:
            break
        if b > a:
            a, b = b, a
        if a == b:
            tot += 1
print(tot)
