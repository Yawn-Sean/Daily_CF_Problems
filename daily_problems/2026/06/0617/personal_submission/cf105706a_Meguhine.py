import sys
from array import array
from bisect import bisect_left

input = lambda: sys.stdin.readline().rstrip()
M = 18


def solve() -> str:
    n, Q = map(int, input().split())
    a = list(map(int, input().split()))
    pos = [[] for _ in range(n + 1)]
    for i, x in enumerate(a):
        pos[x].append(i)
    pos_1, len_1 = pos[1], len(pos[1])
    to = [array('i', [-1] * n) for _ in range(M)]
    to0 = to[0]
    for x in range(1, n):
        p, q = pos[x], pos[x + 1]
        j, m = 0, len(q)
        for pi in p:
            while j < m and q[j] < pi:
                j += 1
            if j < m:
                to0[pi] = q[j]
    for p in range(1, M):
        for i in range(n):
            j = to[p - 1][i]
            if j != -1:
                to[p][i] = to[p - 1][j]
    outs = [1] * Q
    for idx in range(Q):
        L, R = map(int, input().split())
        i = bisect_left(pos_1, L - 1)
        if i < len_1 and pos_1[i] < R:
            i, res = pos_1[i], 2
            for p in range(M - 1, -1, -1):
                j = to[p][i]
                if j != -1 and j < R:
                    i = j
                    res += 1 << p
            outs[idx] = res
    return ' '.join(map(str, outs))


print('\n'.join(solve() for _ in range(int(input()))))


"""
最坏的情况是什么?
A: 1 2 3 4 5
B: 2 3 4 5 6
发现, 统计 A[L, R] 从左到右, 最长的每次+1 的子序列的长度即可
这个怎么统计呢? 倍增即可
"""
