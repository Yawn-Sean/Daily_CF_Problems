"""
所有连通块的异或之和xors是确定的。如果xors==0，则必可以，否则必须拆分成至少3个异或和相等的连通块。如果k==2则必不可以拆分。否则自底向上递归计算子树异或和，当异或和==xors时连通块数量+1，检查最终连通块数量是否>1即可。
Python使用递归的具体方式详见：https://codeforces.com/contest/1592/submission/256068206。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from functools import reduce

def solve():
    n, k = lii()
    k -= 1
    arr = lii()
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v = lii()
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)

    xors = reduce(int.__xor__, arr, 0)
    if xors == 0:
        return True
    if k == 1:
        return False

    cnt = 0
    def dfs(u, pa):
        nonlocal cnt
        s = arr[u]
        for v in g[u]:
            if v == pa:
                continue
            s ^= dfs(v, u)
        if s == xors:
            cnt += 1
            s = 0
        return s

    dfs(0, -1)
    return cnt > 1

for _ in range(ii()):
    print('YES' if solve() else 'NO')
