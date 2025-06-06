import sys
from bisect import bisect_right
from itertools import accumulate
from math import gcd, lcm

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/930/C

给定大整数闭区间 [1,m] 和 n 个属于大区间的小整数闭区间。
求：确定不是所有数都在一个小区间内的最多询问次数，每次询问可得1个数在多少小区间内
因为要求最多问多少次，所以要尽量晚的确定，只要有一个元素出现次数比左右元素出现次数少（该数肯定不在左右数的所属区间内），那么就可以确定了。
如果和左右相等，那么左右的点都可以和当前点合并到一个区间内，那么最后问这个数就行，次数就是这个数左右的LIS和，枚举这样的数，取最大次数
'''
n, m = RII()
cnt = [0] * (m + 2)
for _ in range(n):
    l, r = RII()
    cnt[l] += 1
    cnt[r + 1] -= 1

cnt = list(accumulate(cnt))

left = [0] * (m + 1)
g = []
for i in range(1, m + 1):
    j = bisect_right(g, cnt[i])
    if j == len(g):
        g.append(cnt[i])
    else:
        g[j] = cnt[i]
    left[i] = j

right = [0] * (m + 1)
g = []
for i in range(m, 0, -1):
    j = bisect_right(g, cnt[i])
    if j == len(g):
        g.append(cnt[i])
    else:
        g[j] = cnt[i]
    right[i] = j

ans = 0
for i in range(1, m + 1):
    ans = mx(ans, left[i] + right[i] + 1)
print(ans)