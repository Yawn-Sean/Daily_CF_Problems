import sys
from typing import List, Tuple

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n, d = map(int, input().split())
    m = n // 2
    if d > m * m * 2:
        return "NO"
    mm = m * 2 + 1
    tot = 0
    outs: List[Tuple] = [()] * n * n
    for x in range(1, mm):
        fx = x + m if x <= m else x - m
        for y in range(1, mm):
            fy = y + m if y <= m else y - m
            outs[tot] = (x, y, fx, fy)
            tot += 1
    if n & 1:
        for i in range(2, n):
            outs[tot] = (n, i, n - i + 1, n)
            tot += 1
            outs[tot] = (n - i + 1, n, n, i)
            tot += 1
        outs[-1] = (1, n, n, n)
        outs[-2] = (n, n, n, 1)
        outs[-3] = (n, 1, 1, n)
    return "YES\n" + '\n'.join(
        map(lambda o: f"{o[0]} {o[1]} {o[2]} {o[3]}", outs)
    )


print('\n'.join(solve() for _ in range(int(input()))))


"""
先考虑对于偶数的 n, 令 m := n//2, 我们构造如下函数:
f(x) = x+m if x<=m else x-m
对于 [1,n]*[1,n] 的每个点 (x,y)
(x,y) <-> (f(x),f(y))
容易发现这是一个一一映射, 并且这种构造就是上界
- 因为考虑 (m,m) 这个点, 他的最远点只有 (n,n)

对于奇数, 构造也是类似的, 先对 (n-1)*(n-1) 的部分应用偶数的构造
然后在 (1,n) (n,n) (n,1) 三个点构造三角形
然后在 最后一行从左到右 和 最后一列从下到上 依次连边
这种构造也是上界, 因为考虑中心点, 他会连到 (1,1), 是最远点之一
"""
