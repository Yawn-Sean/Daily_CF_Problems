# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n, x, y = MI()
nums = [I() for _ in range(n)]
for i in range(n):
    l, r = 1, 10 ** 15
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        if mid // x + mid // y >= nums[i]:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    # print(ans)
    if ans % x == 0 and ans % y == 0:
        print("Both")
    elif ans % x == 0:
        print("Vova")
    elif ans % y == 0:
        print("Vanya")
