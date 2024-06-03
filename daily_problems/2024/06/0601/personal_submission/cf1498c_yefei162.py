# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
mod = 1000000007


tcn = I()
for _tcn_ in range(tcn):
    n, k = MI()
    if k == 1:
        print(1)
        continue
    if n == 1:
        print(2)
        continue
    ans = 1 + n
    a = [1] * (n - 1)
    for i in range(k - 2):
        if i % 2 == 0:
            for j in range(n - 2)[::-1]:
                a[j] = (a[j] + a[j + 1]) % mod
        else:
            for j in range(1, n - 1):
                a[j] = (a[j] + a[j - 1]) % mod
        ans += sum(a)
    print(ans % mod)
