# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())

tcn = I()
for _tcn_ in range(tcn):
    n = I()
    s = input()
    if len(set(s)) == 1:
        print(n)
        continue

    x, y = 1, 1
    cnt = 1
    for c in s:
        if c == 'R':
            y += 1
        elif c == 'D':
            x += 1
        cnt += 1

    ans = n * n - (x * y - cnt)
    if s[0] == 'R':
        ans -= (n - x)
        for i in range(1, len(s)):
            if s[i] == 'R':
                ans -= (n - x)
            else:
                break
    elif s[0] == 'D':
        ans -= (n - y)
        for i in range(1, len(s)):
            if s[i] == 'D':
                ans -= (n - y)
            else:
                break
    print(ans)
