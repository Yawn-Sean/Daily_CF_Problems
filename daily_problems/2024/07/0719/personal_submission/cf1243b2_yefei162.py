# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
YN = lambda x: print('YES' if x else 'NO')


tcn = I()
for _tcn_ in range(tcn):
    n = I()
    s = list(input())
    t = list(input())

    ops = []
    for i in range(n):
        if s[i] == t[i]:
            continue
        if s[i] in s[i + 1:]:
            i1 = s[i + 1:].index(s[i])
            ops.append((i1 + i + 1, i))
            t[i], s[i + i1 + 1] = s[i + i1 + 1], t[i]
        elif t[i] in t[i + 1:]:
            i1 = t[i + 1:].index(t[i])
            ops.append((i, i + i1 + 1))
            s[i], t[i + i1 + 1] = t[i + i1 + 1], s[i]
        elif s[i] in t[i + 1:]:
            i1 = t[i + 1:].index(s[i])
            ops.append((i1 + i + 1, i + i1 + 1))
            t[i + i1 + 1], s[i + i1 + 1] = s[i + i1 + 1], t[i + i1 + 1]
            ops.append((i1 + i + 1, i))
            t[i], s[i + i1 + 1] = s[i + i1 + 1], t[i]
        elif t[i] in s[i + 1:]:
            i1 = s[i + 1:].index(t[i])
            ops.append((i1 + i + 1, i + i1 + 1))
            t[i + i1 + 1], s[i + i1 + 1] = s[i + i1 + 1], t[i + i1 + 1]
            ops.append((i, i + i1 + 1))
            s[i], t[i + i1 + 1] = t[i + i1 + 1], s[i]
        else:
            YN(False)
            break
    else:
        YN(True)
        print(len(ops))
        for i in range(len(ops)):
            print(' '.join(str(x + 1) for x in ops[i]))
