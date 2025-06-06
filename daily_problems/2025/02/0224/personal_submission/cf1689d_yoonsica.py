'''
https://codeforces.com/problemset/problem/1689/D
t 组数据，每组给定一个由字符 W 或 B 组成的 n×m 的矩阵。求这样一个点的坐标，满足其到图中任何一个 B 的最大曼哈顿距离最小。

(x, y) 转换成切比雪夫 (x + y, x - y)
两点间切比雪夫距离 = max(abs(x1 - x2), abs(y1 - y2))
把所有B的切比雪夫坐标排序，
对所有点分别求max(x - x1),max(y - y1)最大值的最小值
'''
import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

# 计算点(x, y)到其他点的最大距离
def cal(x, y, x1, x2, y1, y2):
    tx = mx(x - x1, x2 - x)
    ty = mx(y - y1, y2 - y)
    return mx(tx, ty)


for _ in range(RI()):
    n, m = RII()
    a, b = [], [] # 分别存x + y, x - y
    for i in range(n):
        for j, x in enumerate(RS()):
            if x == 'B':
                # 距离B最大距离的点有四种可能
                a.append(i + j)
                b.append(i - j)
    a.sort()
    b.sort()
    
    ans = [inf, 0]
    for i in range(n):
        for j in range(m):
            # 点(i, j)到其他点的最大距离
            x, y = i + j, i - j
            if cal(x, y, a[0], a[-1], b[0], b[-1]) < cal(ans[0] + ans[1], ans[0] - ans[1], a[0], a[-1], b[0], b[-1]):
                ans = [i, j]

    print(ans[0] + 1, ans[1] + 1)
    