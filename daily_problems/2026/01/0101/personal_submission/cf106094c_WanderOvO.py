"""
首先看一下每个素因子的次数
能开根号的次数，在于次数二进制后边有几个 0，在于最小的那个
我觉得可以二分能开根号的次数
然后 check 一下要操作多少次
假如能开 ans 次根号，则每个数的出现次数后边应该有至少 ans 个 0
我们其实就是考察某个素因子出现次数
然后看还要加多少，能让后 ans 位都是 0
"""

import sys
from collections import defaultdict
from math import sqrt

input = lambda: sys.stdin.readline().rstrip()

MAX_X = 200005
spf = list(range(MAX_X))
r = int(sqrt(MAX_X))
for i in range(2, r + 1):
    if spf[i] == i:
        for j in range(i * i, MAX_X, i):
            if spf[j] == j:
                spf[j] = i

ans = []
def solve():
    x, k = map(int, input().split())
    root = int(sqrt(x))
    cnt = defaultdict(int)

    cnt = []
    while x > 1:
        p = spf[x]
        c = 0
        while x % p == 0:
            x //= p
            c += 1
        cnt.append(c)

    l, r = 0, 70

    def check(ans):
        left_cnt = k
        target = (1 << ans)
        for i in range(len(cnt)):
            q = cnt[i]
            rem = q % target
            if rem != 0:
                left_cnt -= target - rem

        return (left_cnt >= 0)

    while l + 1 < r:
        mid = (l + r) // 2
        if check(mid):
            l = mid
        else:
            r = mid
    if check(r):
        ans.append(r)
    else:
        ans.append(l)

T = int(input())
while T > 0:
    T -= 1
    solve()

print("\n".join(map(str, ans)))
