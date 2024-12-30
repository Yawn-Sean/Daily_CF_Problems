# -*- coding : utf-8 -*-
import sys

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

tcn = 2
for _tcn_ in range(tcn):
    n, m = MI()
    nums = LI()


    def check(k):
        if nums[0] + k >= m:
            pre = 0
        else:
            pre = nums[0]
        for i in range(1, n):
            if nums[i] == pre:
                continue
            elif nums[i] < pre:
                if nums[i] + k >= pre:
                    continue
                else:
                    return False
            else:
                if nums[i] + k >= m and (nums[i] + k) % m >= pre:
                    continue
                else:
                    pre = nums[i]
        return True

    L = 0
    R = m
    ans = m
    while L <= R:
        mid = (L+R)//2
        if check(mid):
            ans = mid
            R = mid - 1
        else:
            L = mid + 1
    print(ans)
