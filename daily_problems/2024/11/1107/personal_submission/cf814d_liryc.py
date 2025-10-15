'''
https://codeforces.com/problemset/submission/814/290319421
814D
2024/11/7 Y2
2000
geometry
'''
#ref
from collections import Counter
from math import pi
from sys import stdin
input = lambda: stdin.readline().strip()

n = int(input())
a = []
for _ in range(n):
    x, y, r = map(int, input().split())
    a.append((-r, x, y))
a.sort()

def isin(i, j):
    global a
    return (a[i][1] - a[j][1]) ** 2 + (a[i][2] - a[j][2]) ** 2 <= (a[i][0] - a[j][0]) ** 2

cn = Counter(i for i in range(n) for j in range(i) if isin(i, j))

ans = 0
for i in range(n):
    if max(0, cn[i] - 1) & 1: 
        ans -= a[i][0] ** 2
    else: 
        ans += a[i][0] ** 2

print(pi * ans)