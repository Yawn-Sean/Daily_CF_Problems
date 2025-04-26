"""
看羊神的代码学一手怎么在二维的矩阵里不用dfs, 用二重循环来构建

卡住的一点是在 * 的周围怎么不重复计算连通块。 Counter学到了

又学了一手字符串矩阵的输出方式
"""
# python代码
n, m = map(int, input().split())
g = [list(input()) for _  in range(n)]
ans = [['.'] * m for i in range(n)]

get = lambda x, y: x * m + y
uf = UnionFind(n * m)

for i in range(n):
    for j in range(m):
        if g[i][j] == '.':
            if i and g[i - 1][j] == '.':
                uf.merge(get(i, j), get(i - 1, j))
            if j and g[i][j - 1] == '.':
                uf.merge(get(i, j - 1), get(i, j))

d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
for i in range(n):
    for j in range(m):
        if g[i][j] == '*':
            cnt = Counter()
            for dx, dy in d:
                a, b = i + dx, j + dy
                if 0 <= a < n and 0 <= b < m and g[a][b] == '.':
                    cnt[uf.find(get(a, b))] = uf.get_size(get(a, b))
                s = sum(cnt.values()) + 1
            ans[i][j] = str(s % 10)
print('\n'.join(''.join(x) for x in ans))
