import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from bisect import bisect_left

n, nc, nd = lii()
coins, diamonds = [], []
for _ in range(n):
    beauty, cost, tp = input().split()
    beauty = int(beauty)
    cost = int(cost)
    if tp == 'C':
        coins.append((cost, beauty))
    else:
        diamonds.append((cost, beauty))

coins.sort()
diamonds.sort()

def calc(arr, money):
    premax = [0] * (len(arr)+1)
    ans = 0
    for i, (c, b) in enumerate(arr):
        if c >= money:
            break
        j = bisect_left(arr, (money-c+1, ), hi=i)
        if j > 0:
            ans = max(ans, b + premax[j])
        premax[i+1] = max(premax[i], b)
    return ans

ans1 = calc(coins, nc)
ans2 = calc(diamonds, nd)
res1 = max((b for c, b in coins if c <= nc), default=0)
res2 = max((b for c, b in diamonds if c <= nd), default=0)
ans3 = res1 + res2 if res1 and res2 else 0
print(max(ans1, ans2, ans3))