"""
对于 a[i]，其现在在 i，目标是 a[i](i <= a[i]) 或者 a[i] + n(i > a[i])
假如某个 a[j] 的区间是 a[i] 区间的子区间，则在循环右移时 a[j] 会先停下来，导致 a[i] 可以少移动一次
把这些区间都预处理出来，按照左端点排个序（事实上，一直是排好序的）
从右往左扫描区间，把右端点用树状数组维护，查询目前有多少个右端点 <= 自己的右端点，则可以少走几步
有个问题，假如有 5 个数，有一个区间是 [1, 2]，有一个区间是 [5, 8(3 + 5)]，那么 [1, 2] 也会影响 [5, 8] 的结果
所以我们要先把所有满足 i <= a[i] 的区间的右端点 + n 先扔到树状数组里面才行
"""

import sys


input = lambda: sys.stdin.readline().strip()
T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    a = [0] + list(map(int, input().split()))

    fen = Fenwick(2 * n + 1)
    for i in range(1, n + 1):
        if i <= a[i]:
            fen.add(a[i] + n, 1)

    res = [0 for _ in range(n)]
    for i in range(n, 0, -1):
        if i <= a[i]:
            r = a[i]
        else:
            r = a[i] + n

        res[a[i] - 1] = r - i - fen.query(r)
        fen.add(r, 1)
    print(*res)
