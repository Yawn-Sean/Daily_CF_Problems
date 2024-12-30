# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()

s = input()
n = len(s)
ans = [0] * (n + 1)
f = [0] * (n * n)

idx = lambda i, j: i * n + j

for i in range(n):
    f[idx(i, i)] = 1
for i in range(n - 1):
    if s[i] == s[i + 1]:
        f[idx(i, i + 1)] = 1

for k in range(2, n):
    for i in range(n - k):
        if s[i] == s[i + k] and f[idx(i + 1, i + k - 1)]:
            f[idx(i, i + k)] = 1

g = [0] * (n * n)
for i in range(n):
    g[idx(i, i)] = 1
for i in range(n - 1):
    if s[i] == s[i + 1]:
        g[idx(i, i + 1)] = 2

for k in range(2, n):
    c = (k + 1) // 2
    for i in range(n - k):
        if f[idx(i, i + k)] and g[idx(i, i + c - 1)] == g[idx(i + k - c + 1, i + k)]:
            g[idx(i, i + k)] = g[idx(i, i + c - 1)] + 1

ans = [0] * (n + 1)
for i in range(n):
    for j in range(n):
        k = g[idx(i, j)]
        ans[k] += 1
for i in range(n - 1, -1, -1):
    ans[i] += ans[i + 1]
print(*ans[1:])
