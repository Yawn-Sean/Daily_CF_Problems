# -*- coding: UTF-8 -*-
import sys

global outs
input = lambda: sys.stdin.readline().rstrip()


def solve(_case: int) -> None:
    n = int(input())
    a = sorted(map(int, input().split()))
    outs[_case] = str(min(a[i - 1] ^ a[i] for i in range(1, n)))


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print('\n'.join(outs))
