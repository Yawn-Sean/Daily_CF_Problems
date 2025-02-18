"""
学习新思路，对数组的处理， 可以转化为对图的处理。

这里判断是否是完全图， 取出缺少的边， 再将两个端点分别编号为 1 2 ， 填充其余位置。再将第二个端点改为1， 打印输出
"""
# PYthon代码：
n, m = map(int, input().split())
edges = set()
for i in range(m):
    x,y = map(int, input().split())
    edges.add((min(x, y), max(x, y)))

if m == n * (n - 1) // 2:
    print('NO')
    exit()

edge = None
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        if (i, j) not in edges:
            edge = (i - 1, j - 1)
            break
    if edge:
        break
print('YES')
x, y = edge
res = [0] * n
res[x] = 1
res[y] = 2
cur = 3
for i in range(n):
    if res[i] == 0:
        res[i] = cur
        cur += 1
print(*res)
res[y] = 1
print(*res)
