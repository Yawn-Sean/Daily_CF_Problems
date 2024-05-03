"""
先假设 gcd(a,b)=1 。当区间右端点 x<a+b 时， [0,x] 范围内存在不可到达的位置，需要考虑到达位置 y 所需要的区间右端点 x 的最小值；当区间右端点 x>=a+b 时， [0,x] 范围内的位置均可达，这部分的贡献用等差数列求和即可。
再考虑 g=gcd(a,b)>1 。对 k*g<=x<(k+1)*g ， [0,x] 的可达情况是一样的，因此只需要放大 g 倍，并额外处理余数。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from math import gcd
from heapq import heappush, heappop
inf = 1 << 30

def solve():
    m, a, b = lii()
    g = gcd(a, b)
    a //= g; b //= g
    rem = m % g + 1
    m //= g
    # 这部分几乎就是 Dijkstra
    right = [inf] * (a+b)
    right[0] = 0
    pq = [(0, 0)]
    while pq:
        minr, i = heappop(pq)
        if minr > right[i]:
            continue
        if i+a < a+b:
            if (tmp := max(i+a, minr)) < right[i+a]:
                right[i+a] = tmp
                heappush(pq, (tmp, i+a))
        if i-b >= 0:
            if (tmp := minr) < right[i-b]:
                right[i-b] = tmp
                heappush(pq, (tmp, i-b))

    ans = 0
    cur = 0
    pq = []
    for i, r in enumerate(right):
        # [0,r] 的可达位置有多少
        heappush(pq, r)
        while pq and pq[0] <= i:
            heappop(pq)
            cur += 1
        if i == m:
            ans += cur * rem
            break
        ans += cur * g

    if m >= a+b:
        ans += ((a+b+1+m) * (m-(a+b)) // 2) * g  # a+b+1 到 m 求和
        ans += (m+1) * rem
    return ans

   
print(solve())