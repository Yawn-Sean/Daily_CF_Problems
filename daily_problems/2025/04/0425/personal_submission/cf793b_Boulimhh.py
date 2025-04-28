"""
写了个dfs(i, j, turn, direction),  python wa了41， 不知道啥样例

转了bfs， 一直爆内存， 太菜了

只能学羊神写法了， 还得是思维

枚举3条（也有可能小于3条路径）

分别判断每条路径是否成立

"""
# python代码
n, m = map(int, input().split())
g = [list(input()) for _ in range(n)]

x1, y1, x2, y2 = 0, 0, 0, 0

for i in range(n):
    for j in range(m):
        if g[i][j] == "S":
            x1, y1 = i, j
        if g[i][j] == "T":
            x2, y2 = i, j

c = [[1 if g[i][j] == "*" else 0 for j in range(m)] for i in range(n)]

def f(x3, y3, x4, y4):
    if x3 > x4: x3, x4 = x4, x3
    if y3 > y4: y3, y4 = y4, y3
    for i in range(x3, x4 + 1):
        for j in range(y3, y4 + 1):
            if c[i][j]:
                return False
    return True

for i in range(n):
    if f(x1, y1, i, y1) and f(i, y1, i, y2) and f(i, y2, x2, y2):
        print("YES")
        break
else:
    for i in range(m):
        if f(x1, y1, x1, i) and f(x1, i, x2, i) and f(x2, i, x2, y2):
            print("YES")
            break
    else:
        print("NO")   
