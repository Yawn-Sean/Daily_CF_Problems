# -*- coding: UTF-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()


n, W = map(int, input().split())

if n == 1:
    print(W)
    sys.exit(0)

a = sorted(map(int, input().split()))
ans, s = 0, 0
for i, x in enumerate(a):
    ans += x * i - s
    s += x
ans = (ans << 1) / n
ans += W
print(f"{ans:.8f}")
