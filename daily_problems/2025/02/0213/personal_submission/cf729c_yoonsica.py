import sys
from bisect import bisect_left

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/729/C
n,k,s,t
n种车，每种费用c,邮箱容量v
从0出发，到s处，在t时间内的最小花费
路上有k个加油站，位置给定

车子有两种模式，普通模式，1公里，消耗1汽油，2分钟
快速模式，1公里消耗2汽油， 1分钟

思路：
先考虑一辆车的最小花费，加油不花钱，费用都在租车上

所以选租车费用最小的，邮箱容量最大的，直接二分答案，如果答案=mid，则找费用<=mid的最大的容量V，check

如何check一辆车在t时间内能否到达s

费用固定了，剩下的就是减少时间消耗，那么能快速就不慢速，保证能到达下一个加油站即可
假设当前距离下一个加油站有d的距离，快速需要d分钟，2*d汽油，如果邮箱容量v >= 2 * d，没问题
如果v < 2 * d,那么 设快速走x，慢速走d - x,要求x*2 + d - x <= v, x <= d
x + d <= v,x <= v - d, x = mx(0, mn(d, v - d))
如果d > v,没法走到下一个加油站
'''
n, k, s, t = RII()

a = []
for _ in range(n):
    a.append(RILIST())

a.sort()
left_max_v = [a[0][1]]
for i in range(1, n):
    left_max_v.append(mx(left_max_v[-1], a[i][1]))

b = sorted(RILIST()) + [s]

l, r = -1, a[-1][0] + 1


def check(mid):
    # 费用mid
    j = bisect_left(a, [mid + 1, 0]) - 1
    if j < 0:
        return False
    v = left_max_v[j]
    # 判断v能否走完
    cur = tt = 0
    for x in b:
        d = x - cur
        if d > v:
            return False
        y = mx(0, mn(d, v - d))
        tt += y + (d - y) * 2
        if tt > t:
            return False
        cur = x
    return True


while l + 1 < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid
print(r if r < a[-1][0] + 1 else -1)


'''
2 1 100 18
10 4
20 6
99
'''