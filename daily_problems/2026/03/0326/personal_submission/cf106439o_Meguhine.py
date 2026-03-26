# -*- coding: UTF-8 -*-
import sys
from array import array
from math import gcd

global outs
input = lambda: sys.stdin.readline().rstrip()


def solve(_case: int) -> None:
    n = int(input())
    a = list(map(int, input().split()))
    ans = array('b', [0] * n)

    def work(l: int, r: int, g: int) -> bool:
        f = True
        for i in range(l, r + 1):
            if a[i] % g:
                if not f:
                    return False
                f = False
        return True

    f, g = 0, 0
    for i in range(n - 1):
        ng = gcd(g, a[i])
        if ng != g:
            g = ng
            f = work(i + 1, n - 1, g)
        ans[i] |= f

    f, g = 0, 0
    for i in range(n - 1, 0, -1):
        ng = gcd(g, a[i])
        if ng != g:
            g = ng
            f = work(0, i - 1, g)
        ans[i - 1] |= f

    outs[_case] = str(sum(ans))


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print('\n'.join(outs))
