"""
思路： 首先， 这个题一开始没读懂， 四处找分析才读懂这个题。

题目大致是，在经过所有 p 点的最短路上，去掉一些点，使原始最短路不变。

首先是构造Floyd矩阵， 再用Floyd算法求最短路。 最后判断要遍历的点是不是可以去掉。
"""
#python代码：
inf = 10 ** 9
n = int(input())
g = []
for _ in range(n):
    l = [1 if c == '1' else 10 ** 9 for c in input()]
    g.append(l)
for i in range(n):
    g[i][i] = 0
  
m = int(input())
p = list(map(int, input().split()))
for k in range(n):
    for i in range(n):
        for j in range(n):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

ans = [p[0]]
for i in range(1, m - 1):
    x, y, z = p[i + 1] - 1, p[i] - 1, ans[-1] - 1
    if g[z][x] != g[z][y] + g[y][x]:
        ans.append(p[i])
ans.append(p[-1])
print(len(ans))
print(*ans)
