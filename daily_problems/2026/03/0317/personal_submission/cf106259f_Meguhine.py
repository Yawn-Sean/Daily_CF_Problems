# -*- coding: UTF-8 -*-
import sys

global outs
input = lambda: sys.stdin.readline().rstrip()


MOD = 998244353


def solve(_case: int) -> None:
    n = int(input())
    a = sorted(map(int, input().split()))
    ans, s = 0, 0
    for i, x in enumerate(a):
        ans += x * i - s
        s += x
    ans %= MOD
    ans *= pow(n, MOD - 2, MOD) * 2
    outs[_case] = str(ans % MOD)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print('\n'.join(outs))
