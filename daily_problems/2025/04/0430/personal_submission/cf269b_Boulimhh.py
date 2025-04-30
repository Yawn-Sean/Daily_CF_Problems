"""
少关注了顺序输入这一点， 所以没在 LIS 上想

看了题解才发现是这， 模型抽象能力有点差

写了二分 + 贪心， 复习下写法
"""
# python代码
n, m = map(int, input().split())
pos = []
for _ in range(n):
    a, b = input().split()
    pos.append(int(a))

g = []
for x in pos:
    j = bisect_right(g, x)
    if j == len(g):
        g.append(x)
    else:
        g[j] = x
print(n - len(g))
