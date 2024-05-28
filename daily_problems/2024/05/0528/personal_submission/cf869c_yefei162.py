# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
MI = lambda: map(int, input().split())
mod2 = 998244353

fact = Factorial(5005, mod2)

tcn = 4
for _tcn_ in range(tcn):
    a, b, c = MI()
    ans1 = 0
    for k in range(min(a, b) + 1):
        ans1 += fact.fac(k) * fact.combi(a, k) * fact.combi(b, k)

    ans2 = 0
    for k in range(min(a, c) + 1):
        ans2 += fact.fac(k) * fact.combi(a, k) * fact.combi(c, k)

    ans3 = 0
    for k in range(min(c, b) + 1):
        ans3 += fact.fac(k) * fact.combi(c, k) * fact.combi(b, k)

    ans = ans1 * ans2 * ans3 % mod2
    print(ans)
