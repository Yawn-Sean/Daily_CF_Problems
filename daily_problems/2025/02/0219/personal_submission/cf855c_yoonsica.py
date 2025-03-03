import sys
from types import GeneratorType

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
mod = 10**9 + 7


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if isinstance(to, GeneratorType):
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)
    
    return wrappedfunc


'''
https://codeforces.com/problemset/problem/855/C
一棵树，每个节点可以染m种颜色之一，y是特殊颜色，要求整颗树染成k的节点数不超过V，
同时，染成k的节点的相邻节点只能染[1:y - 1]的颜色，求染色方案数。


考虑dp：
以i为根的子树，有j个节点染成y,且当前节点染色编号大于等于小于y的方案数=f[i][j][k]
答案为sum(f[1][:x][k])

树形背包
'''
n, m = RII()
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = RII()
    g[u].append(v)
    g[v].append(u)

y, V = RII()

f = [[[0]*3 for _ in range(V + 1)] for _ in range(n + 1)]
tmp = [[0]*3 for _ in range(V + 1)] # 辅助数组
sz = [0] * (n + 1) #记录子数节点数

@bootstrap
def dfs1(u, fa):
    sz[u] = 1
    for v in g[u]:
        if v == fa:
            continue
        yield dfs1(v, u)
        sz[u] += sz[v]
    yield 1

dfs1(1, 0)

@bootstrap
def dfs(u, fa):
    # 全都不染k,当前节点颜色小于y
    f[u][0][0] = y - 1
    # 当前染成y
    f[u][1][1] = 1
    # 当前> y
    f[u][0][2] = m - y
    for v in g[u]:
        if v == fa:
            continue
        yield dfs(v, u)
        for j in range(V + 1):
            for k in range(3):
                tmp[j][k] = f[u][j][k]
                f[u][j][k] = 0
        for j in range(mn(sz[u], V), -1, -1): # 总共有多少个
            for k in range(mn(sz[v], j) + 1): # 分给v多少个
                # 当前节点小于y，子节点随意
                f[u][j][0] = (f[u][j][0] + tmp[j - k][0] * sum(f[v][k])) % mod
                # 当前节点=y，子节点小于y
                f[u][j][1] = (f[u][j][1] + tmp[j - k][1] * f[v][k][0]) % mod
                # >y，子节点不能等于y
                f[u][j][2] = (f[u][j][2] + tmp[j - k][2] * (f[v][k][0] + f[v][k][2])) % mod
    yield 1

dfs(1, 0)
ans = 0
for j in range(V + 1):
    for k in range(3):
        ans = (ans + f[1][j][k]) % mod
print(ans)