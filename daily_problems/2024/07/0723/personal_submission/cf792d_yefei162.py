# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())


def convert(x):
    target = x
    x = (n + 1) // 2
    y = 1
    m = x // 2
    while x != target:
        if x < target:
            y = y * 2 + 1
            x += m
        elif x > target:
            y = y * 2
            x -= m
        else:
            break
        m //= 2
    return y


def revert(y):
    x = (n + 1) // 2
    m = x // 2
    for c in bin(y)[3:]:
        if c == '0':
            x -= m
        elif c == '1':
            x += m
        m //= 2
    return x


n, q = MI()

for _ in range(q):
    i1 = I()
    path = input()
    i2 = convert(i1)
    # print(i1, i2)
    for c in path:
        if c == 'U':
            if i2 == 1:
                continue
            i2 //= 2
        elif c == 'L':
            if i2 * 2 > n:
                continue
            i2 = i2 * 2
        elif c == 'R':
            if i2 * 2 + 1 > n:
                continue
            i2 = i2 * 2 + 1

    i3 = revert(i2)
    print(i3)
