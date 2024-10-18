"""
思路: 跟着🐏的代码过一遍

首先让各个关卡全部都传上去，看作连到一个节点的图。  再遍历k个等级， 将 1 - k 等级的差值依次算出来， 当作节点连起来。

得到一个图， 将其最小生成树算出来， 再打印总权重和各自的等级。

"""
#python代码：
n, m, k, w = map(int, input().split())
g = []
for _ in range(k):
    g.append([input() for _ in range(n)])
us = []
vs = []
ws = []
for i in range(k):
    us.append(i)
    vs.append(k)
    ws.append(n * m)
    
    for j in range(i):
        cnt = 0
        for x in range(n):
            for y in range(m):
                if g[i][x][y] != g[j][x][y]:
                    cnt += 1
        us.append(i)
        vs.append(j)
        ws.append(cnt * w)

e = len(ws)
union = UnionFind(k + 1)
path = [[] for _ in range(k + 1)]

ans = 0
for i in sorted(range(e), key=lambda x: ws[x]):
    if union.merge(us[i], vs[i]):
        path[us[i]].append(vs[i])
        path[vs[i]].append(us[i])
        ans += ws[i]
print(ans)
parent = [-1] * (k + 1)
stk = [k]

while stk:
    u = stk.pop()
    for v in path[u]:
        if parent[u] != v:
            parent[v] = u
            stk.append(v)
            print(f'{v + 1} {parent[v] + 1 if parent[v] != k else 0}')

