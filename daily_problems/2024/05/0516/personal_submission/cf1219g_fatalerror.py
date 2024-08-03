"""
寻找最大的 k(=2,3,4) 个元素之和时， nlargest 居然是可以压线通过的，虽然比朴素的逐个比较的方法慢。
能通过的可能原因：C 层面的优化、列表生成式的优化等。
不能通过的可能原因：数组大小顺序使逐个比较的比较次数明显少于 nlargest （可以参考 heapq 源码注释）、创建列表的额外时间等。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from heapq import nlargest
max_ = lambda a, b: a if a > b else b

def solve():
    m, n = lii()
    grid = [lii() for _ in range(m)]
    if m > n:
        m, n = n, m
        grid = list(zip(*grid))
    rowsum = [sum(row) for row in grid]
    colsum = [sum(col) for col in zip(*grid)]

    ans = 0
    ans = max_(ans, sum(nlargest(4, rowsum)))
    ans = max_(ans, sum(nlargest(4, colsum)))

    for j, col in enumerate(zip(*grid)):
        for i, x in enumerate(col):
            rowsum[i] -= x
        ans = max_(ans, colsum[j] + sum(nlargest(3, rowsum)))
        for i, x in enumerate(col):
            rowsum[i] += x
    for i, row in enumerate(grid):
        for j, x in enumerate(row):
            colsum[j] -= x
        ans = max_(ans, rowsum[i] + sum(nlargest(3, colsum)))
        for j, x in enumerate(row):
            colsum[j] += x

    for i1 in range(m):
        for i2 in range(i1+1, m):
            for j in range(n):
                colsum[j] -= grid[i1][j] + grid[i2][j]
            ans = max_(ans, rowsum[i1] + rowsum[i2] + sum(nlargest(2, colsum)))
            for j in range(n):
                colsum[j] += grid[i1][j] + grid[i2][j]

    return ans

print(solve())