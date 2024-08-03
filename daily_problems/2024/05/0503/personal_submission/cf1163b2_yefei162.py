# -*- coding : utf-8 -*-
import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    nums = LI()
    cnt = [0] * (n + 1)
    hst = Counter()
    ans = 1
    for i, num in enumerate(nums, start=1):
        cnt[hst[num]] -= 1
        hst[num] += 1
        cnt[hst[num]] += 1
        # print(cnt)
        if hst[num] * cnt[hst[num]] == i:
            if i + 1 <= n:
                ans = max(ans, i + 1)
        if hst[num] * cnt[hst[num]] + hst[num] + 1 == i and cnt[hst[num] + 1] == 1:
            ans = max(ans, i)
        if hst[num] * cnt[hst[num]] == i - 1:
            ans = max(ans, i)
    print(ans)
