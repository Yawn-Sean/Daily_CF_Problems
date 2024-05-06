# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())

tcn = I()
for _tcn_ in range(tcn):
    n, k = MI()
    nums = LI()
    d = 0x3f3f3f3f
    ans = -1
    for i in range(n - k):
        d1 = (nums[i + k] - nums[i] + 1) // 2
        if d1 < d:
            d = d1
            ans = (nums[i + k] + nums[i]) // 2
    print(ans)
