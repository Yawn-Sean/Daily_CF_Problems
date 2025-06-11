import sys
from bisect import bisect_left, bisect_right
inf = float('inf')
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LI = lambda: list(input().split())

n, c, d = MII()
coins, diamonds = [], []
for _ in range(n):
    beauty, cost, t = LI()
    beauty, cost = int(beauty), int(cost)
    if t == 'C':
        coins.append((cost, beauty))
    else:
        diamonds.append((cost, beauty))
coins.sort()
diamonds.sort()

def f(nums, price):
    pre_max = [0] * (len(nums) + 1)
    res = 0
    for i, (cost, beauty) in enumerate(nums):
        if cost >= price:
            break
        j = bisect_left(nums, (price - cost + 1, -inf), hi=i)
        if j:
            res = max(res, beauty + pre_max[j])
        pre_max[i + 1] = max(pre_max[i], beauty)
    return res

single = max([beauty for cost, beauty in coins if cost <= c], default=-inf) + \
         max([beauty for cost, beauty in diamonds if cost <= d], default=-inf)
double = max(f(coins, c), f(diamonds, d))
print(max(single, double))
