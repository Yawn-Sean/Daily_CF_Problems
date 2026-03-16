# -*- coding: UTF-8 -*-
import sys

global outs
input = lambda: sys.stdin.readline().rstrip()


def solve(_case: int) -> None:
    n, m, sx, sy, tx, ty = map(int, input().split())
    if n & 1 and m & 1:
        outs[_case] = "NO"
        return
    if m == 1:
        n, m = m, n
        sx, sy = sy, sx
        tx, ty = ty, tx
    if n == 1:
        x, y = (sy, ty) if sy < ty else (ty, sy)
        outs[_case] = "NO" if ((x - 1) & 1 or (y - x - 1) & 1 or (m - y) & 1) else "YES"
        return
    s = (sx & 1) ^ (sy & 1)
    t = (tx & 1) ^ (ty & 1)
    outs[_case] = "YES" if s != t else "NO"


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print('\n'.join(outs))
