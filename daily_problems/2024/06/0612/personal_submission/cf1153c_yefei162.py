# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    s = list(input())
    m = n // 2 - s.count('(')
    if n % 2 or m < 0:
        print(":(")
        continue

    cur = 0
    for i in range(n):
        if s[i] == '(':
            cur += 1
        elif s[i] == ')':
            cur -= 1
        else:
            if m > 0:
                s[i] = '('
                cur += 1
                m -= 1
            else:
                s[i] = ')'
                cur -= 1
        if cur < 0 or (cur == 0 and i != n - 1):
            print(':(')
            break
    else:
        print(''.join(s))
