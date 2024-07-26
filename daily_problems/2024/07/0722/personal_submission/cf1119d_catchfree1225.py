import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from itertools import accumulate
from bisect import bisect_left

def solve(): 
    n = len(a)
    diff = sorted(a[i + 1] - a[i] for i in range(n - 1))
    preSum = list(accumulate(diff, initial=0))
    
    # 數組無限延伸，只需要考慮開頭
    # 等於拿一個標尺在頭上移動，比對ai->ai+1的差
    # 差值小於subL取前綴和，大於等於subL取subL
    # extra = min(subL, 差值)
    ans = []
    for _ in range(int(input())):
        l, r = MII()
        subL = r - l + 1 # 標尺長度
        p = bisect_left(diff, subL)
        contrib_lt = preSum[p]
        contrib_ge = (n - p) * subL
        ans.append(contrib_lt + contrib_ge)
    print(*ans) 
               
for _ in range(1):
    n = int(input())
    a = sorted(MII())
    solve()