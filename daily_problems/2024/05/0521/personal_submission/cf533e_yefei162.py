# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    S = input()
    T = input()
    i = 0
    while i < n:
        if S[i] == T[i]:
            i += 1
        else:
            break
    j = n - 1
    while j >= 0:
        if S[j] == T[j]:
            j -= 1
        else:
            break

    if i > j:
        ans = (n + 1) * 26
    elif j == i:
        ans = 2
    else:
        for i1 in range(i, j):
            if S[i1] == T[i1 + 1]:
                continue
            else:
                ans = 0
                break
        else:
            ans = 1

        for i1 in range(i, j):
            if S[i1 + 1] == T[i1]:
                continue
            else:
                ans += 0
                break
        else:
            ans += 1

    print(ans)
