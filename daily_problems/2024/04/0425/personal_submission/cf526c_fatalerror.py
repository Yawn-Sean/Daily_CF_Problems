"""
如果 w1, w2 至少有一个不小于 sqrt(c) ，不妨设较大单价者为 w1 ，则 w1 的数量不会超过 c/w1<sqrt(c) ，可以枚举 w1 的数量。
如果 w1, w2 均小于 sqrt(c) ，不妨设较小性价比者为 w1 、满足 h1/w1<h2/w2 ，则在 w1*w2<=c 的花费下， w2 个 w1 一定比 w1 个 w2 价值大。因此最优方案下 w1 的数量不会超过 w2 ，同样可以枚举 w1 的数量。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

c, h1, h2, w1, w2 = lii()

if w1*w1 >= c or w2*w2 >= c:
    if w1 < w2:
        h1, h2 = h2, h1
        w1, w2 = w2, w1
    upper = c // w1
else:
    if w1*h2 < w2*h1:
        h1, h2 = h2, h1
        w1, w2 = w2, w1
    # upper = w2 - 1
    from math import lcm
    upper = lcm(w1, w2)//w1 - 1

ans = max(x1*h1 + (c-x1*w1)//w2*h2 for x1 in range(upper+1))
print(ans)