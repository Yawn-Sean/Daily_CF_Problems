# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 2
for _tcn_ in range(tcn):
    s = input()
    n = len(s)
    fb = [0] * (n + 1)
    fw = [0] * (n + 1)
    for i in range(n):
        if s[i] == 'b':
            fb[i + 1] = fw[i] + 1
        elif s[i] == 'w':
            fw[i + 1] = fb[i] + 1
    ans1 = max(fb)
    ans2 = max(fw)

    ans3 = 0
    if s[0] == 'w' and s[-1] == 'b':
        ans3 += 2
        nex = 'b'
        for i in range(1, n):
            if s[i] == nex:
                ans3 += 1
                nex = 'w' if nex == 'b' else 'b'
            else:
                break
        nex = 'w'
        for j in range(n - 2, -1, -1):
            if s[j] == nex:
                ans3 += 1
                nex = 'w' if nex == 'b' else 'b'
            else:
                break
        ans3 = min(ans3, n)

    ans4 = 0
    if s[0] == 'b' and s[-1] == 'w':
        ans4 += 2
        nex = 'w'
        for i in range(1, n):
            if s[i] == nex:
                ans4 += 1
                nex = 'w' if nex == 'b' else 'b'
            else:
                break
        nex = 'b'
        for j in range(n - 2, -1, -1):
            if s[j] == nex:
                ans4 += 1
                nex = 'w' if nex == 'b' else 'b'
            else:
                break
        ans4 = min(ans4, n)
    ans = max(ans1, ans2, ans3, ans4)
    print(ans)

