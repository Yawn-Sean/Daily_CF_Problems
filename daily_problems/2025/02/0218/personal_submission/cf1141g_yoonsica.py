import random
import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict
from functools import cmp_to_key
from heapq import heappush, heappop
from math import inf, sqrt
from types import GeneratorType

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if isinstance(to, GeneratorType):
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)
    
    return wrappedfunc


'''
n个点，n-1条边，要求给每条边涂色，每个点连接的边中，如果有两个边颜色相同，则这个点为坏点，
求至少需要几种颜色，才能满足最多有k个坏点，输出涂色方案。

一个点度数为d，那么如果这个点是坏点，只需要1种颜色
如果这个点不是坏点，那么需要d个颜色。
考虑按度数对点排序，第k + 1个点的度数就是最少需要的颜色。
涂色方案可以通过dfs一遍完成
'''
n, k = RII()
g = [[] for _ in range(n + 1)]
d = [0] * (n + 1)
for i in range(n - 1):
    u, v = RII()
    g[u].append((v, i))
    g[v].append((u, i))
    d[u] += 1
    d[v] += 1

a = sorted(range(1, n + 1), key=lambda i: -d[i])
cnt = d[a[k]]
print(cnt)

ans = [1] * (n - 1)
@bootstrap
def dfs(u, fa, fa_c):
    if d[u] > cnt: # 坏点
        if fa_c == 0:
            fa_c = 1
        for v, i in g[u]:
            if v != fa:
                ans[i] = fa_c
                yield dfs(v, u, fa_c)
    else:
        c = 1
        for v, i in g[u]:
            if v != fa:
                if c == fa_c:
                    c += 1
                ans[i] = c
                yield dfs(v, u, c)
                c += 1
    yield 0

dfs(a[0], 0, 0)
print(' '.join(map(str, ans)))