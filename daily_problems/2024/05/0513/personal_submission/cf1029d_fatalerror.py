import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from collections import defaultdict
from random import shuffle

MX = 10
n, k = lii()
arr = lii()
shuffle(arr)  # 防卡哈希

pow10 = [1]
for _ in range(MX):
    pow10.append(pow10[-1] * 10 % k)

def calc(arr):
    rems = [defaultdict(int) for _ in range(MX+1)]
    ans = 0
    for x in arr:
        for trail in range(1, MX+1):
            ans += rems[trail].get((-x*pow10[trail])%k, 0)
        rems[len(str(x))][x%k] += 1
    return ans

ans = calc(arr)
arr.reverse()
ans += calc(arr)
print(ans)