"""
统计每个元素出现次数。枚举 s ，对每个元素的出现次数 v ，判断 s 是否满足 a*s+b*(s-1)=v 有解，最大的 s 即对应最小的 m 。判断方法见代码。
在枚举 s 时，从最小出现次数 minfreq+1 开始由大到小枚举，枚举次数不超过 minfreq ，单次枚举计算次数不超过 n/minfreq ，所以总复杂度是 O(n) 。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from collections import defaultdict

def solve():
    n = ii()
    arr = lii()
    cnt = defaultdict(int)
    for x in arr:
        cnt[x] += 1
    freq = defaultdict(int)
    for v in cnt.values():
        freq[v] += 1

    for s in range(min(freq.keys())+1, 1, -1):
        if all(v%(s-1) <= v//(s-1) for v in freq.keys()):
            return sum((v+s-1)//s * c for v, c in freq.items())
    return n

for _ in range(ii()):
    print(solve())