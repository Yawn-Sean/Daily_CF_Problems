"""
被狠狠虐的一集

一开始二维数组原地处理 + nlogn 排序， 直接超时

换成了计数排序， 之后统计后缀， 结果还是超时

思来想去看看羊神题解， 结果是一维统计， 换成一维数组后过了

二维数组超时， 狠狠记住了
"""

# python代码：
n, m = map(int, input().split())
g = [[int(c) for c in list(input())]for _ in range(n)]
c = [0] * (m + 2)
h = [0] * n
res = 0
for j in range(m):
    for i in range(n):
        if g[i][j]: h[i] += 1
        else: h[i] = 0

    c = [0] * (m + 1)
    for i in range(n):
        c[h[i]] += 1
    cnt = 0
    for i in range(m, 0, -1): 
        cnt += c[i] 
        res = fmax(res, cnt * i)
print(res)
