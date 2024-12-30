import sys
import bisect
from itertools import accumulate
sys.setrecursionlimit(int(1e5))

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

def partition(l, r):
    if l == r:
        s.add(nums[l])
        return
    
    if nums[l] != nums[r]: # 递归不下去了
        k = bisect.bisect(nums, (nums[l] + nums[r]) // 2) - 1
        s.add(acc[k + 1] - acc[l])
        s.add(acc[r + 1] - acc[k + 1])
        partition(l, k)
        partition(k + 1, r)

t = II()
ans = []
for _ in range(t):
    n, q = MII()
    nums = LMII()
    nums.sort()
    acc = list(accumulate(nums, initial=0))
    # 先把所有值预处理出来，然后查找
    s = set([acc[n]])
    partition(0, n - 1)
    for _ in range(q):
        x = II()
        if x in s:
            ans.append("Yes")
        else:
            ans.append("No")
print('\n'.join(ans))