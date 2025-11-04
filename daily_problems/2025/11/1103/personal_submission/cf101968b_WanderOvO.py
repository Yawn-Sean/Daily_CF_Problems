"""
看错了题目，是选两个点，求 min 的 x 和 y 作为左下角的点，max 作为右上角的点，而不是直接选左下和右上的点
但是刚才的一部分分析仍然成立，对于每种配对，假如有交，则交的都一样
我们考虑有交的配对，交出来是什么样的
假设 (x[i], y[i]) 和 (x[j], y[j]) 配对，其左下角是 (min(x[i], x[j]), min(y[i], y[j]))
所有的交出来的左下角，就是 min 里面的 max
右上角就是 max 里面的 min
然后要求右上角严格在左下角的右上方，不能共线
通过画图，我们发现，其实交出来的东西，左下角的横纵坐标就是第 n 小的横纵坐标，右上角的就是第 n + 1 小的
假如有一组配对，其两个横或纵坐标都比第 n 小的大，就废了，同样，如果其两个横或纵坐标都比第 n + 1 小的小，也就废了
我们在图中画出来交的那一块，发现通过它能分成 9 个区域
除去中间十字区域的 5 块不能选，另外 4 个区域是其他点所在的区域
我们相当于只能左上配右下，或左下配右上
配的时候似乎是随便配就好了
具体算出来是多少？
我们假设左上角有 c1 个，右下角有 c2 个
假如 c1 != c2，则总有配不上的，配不上好像就交不出来呢，所以必须得有 c1 == c2
然后其实就是 c1! 种方案
另外一边也可以算出来，二者相乘就好
"""
import sys

input = lambda: sys.stdin.readline().rstrip()
T = int(input())
mod = 10 ** 9 + 7
N = 200010
fact = [1 for _ in range(N)]
for i in range(1, N):
    fact[i] = fact[i - 1] * i % mod

while T > 0:
    T -= 1
    n = int(input())
    points = []
    xs = []
    ys = []
    nn = 2 * n
    for i in range(nn):
        x, y = map(int, input().split())
        points.append((x, y))
        xs.append(x)
        ys.append(y)

    xs.sort()
    ys.sort()

    if xs[n - 1] == xs[n] or ys[n - 1] == ys[n]:
        print("0")
        continue

    # 左下，左上，右下，右上
    c = [0 for _ in range(5)]
    for i in range(nn):
        if points[i][0] <= xs[n - 1] and points[i][1] <= ys[n - 1]:
            c[0] += 1
        elif points[i][0] <= xs[n - 1] and points[i][1] >= ys[n]:
            c[1] += 1
        elif points[i][0] >= xs[n] and points[i][1] <= ys[n - 1]:
            c[2] += 1
        else:
            c[3] += 1

    if c[0] != c[3] or c[1] != c[2]:
        print("0")
        continue

    res = fact[c[0]] * fact[c[1]] % mod
    print(res)
