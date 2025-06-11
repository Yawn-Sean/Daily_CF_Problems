# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(GMI())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    nums = LGMI()
    cnt = [0] * n

    mx1, mx2 = -1, -1
    for x in nums:
        if x > mx1:
            cnt[x] -= 1
            mx1, mx2 = x, mx1
        elif x > mx2:
            cnt[mx1] += 1
            mx2 = x
    ans = cnt.index(max(cnt)) + 1
    print(ans)
