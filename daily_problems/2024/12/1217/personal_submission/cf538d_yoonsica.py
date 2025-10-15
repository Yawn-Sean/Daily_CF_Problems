n = RI()
g = []
for _ in range(n):
    g.append(RS())

d = defaultdict(lambda:1) # 默认每个方向都可以

for i, row in enumerate(g):
    for j, c in enumerate(row):
        if c == 'o': # 棋子
            for x in range(n):
                for y in range(n):
                    if g[x][y] == '.': # 这个方向不行
                        d[x - i, y - j] = 0

t = [[0]*(n + 1) for _ in range(1 + n)] # 记录所有棋子的攻击范围
for i, row in enumerate(g):
    for j, c in enumerate(row):
        if c == 'o':
            # 判断每个能走的方向
            for x in range(n):
                for y in range(n):
                    if d[x - i, y - j]:
                        t[x][y] = 1
flag = True
for i, row in enumerate(g):
    for j, c in enumerate(row):
        if c != 'o':
            flag &= ((c == 'x') == (t[i][j] == 1))

if not flag:
    print('NO')
else:
    print('YES')
    ans = [['.']*(2*n - 1) for _ in range(2*n - 1)]
    for i in range(1 - n, n): # dx, dy的变化范围从(0,0) 到 (n - 1, n - 1)
        for j in range(1 - n, n):
            if d[i, j] == 1:
                ans[i + n - 1][j + n - 1] = 'x'
    ans[n - 1][n - 1] = 'o'
    for row in ans:
        print(''.join(row))