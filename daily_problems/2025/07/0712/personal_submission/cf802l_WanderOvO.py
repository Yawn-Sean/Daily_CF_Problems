"""
f[i] 表示从 i 开始走，走到叶子的期望步数
对于叶子 u，f[u] = 0
对于叶子 v 的父亲 u，有 f[u] = (f[p[u]] + sum(w)) / d[u]
那么 f[p[u]] = (sum(k * f[p[u]] + b) + sum(w) + f[f[p[u]]]) / d[p[u]]
对于每个点，都维护 k 和 b，说明 f[u] = k[u] * f[p[u]] + b[u]
v 是 u 的孩子，则先把所有孩子的 k[v] 和 b[v] 求和，得到 sum_k 和 sum_b，然后把所有相邻的 w 求和，得到 sum_w
f[u] = (sum_k * f[u] + sum_b + sum_w + f[p[u]]) / d[u]
(d[u] - sum_k) * f[u] - sum_b - sum_w = f[p[u]]
f[u] = (sum_b + sum_w) / (d[u] - sum_k) + f[p[u]] / (d[u] - sum_k)
k[u] = 1 / (d[u] - sum_k)
b[u] = (sum_b + sum_w) / (d[u] - sum_k)
u 为根结点，则没有 f[p[u]] 这一项了，就可以解出来了
"""
import queue

n = int(input())
e = [[] for _ in range(n + 1)]
d = [0 for _ in range(n + 1)]
k = [0 for _ in range(n + 1)]
b = [0 for _ in range(n + 1)]
vis = [False for _ in range(n + 1)]
fa = [-1 for _ in range(n + 1)]
is_leaf = [True for _ in range(n + 1)]
mod = 10 ** 9 + 7

for i in range(n - 1):
    u, v, c = map(int, input().split())
    e[u].append((v, c))
    e[v].append((u, c))
    d[u] += 1
    d[v] += 1

order = [0]
vis[0] = True
for u in order:
    for edge in e[u]:
        v = edge[0]
        if not vis[v]:
            is_leaf[u] = False
            order.append(v)
            fa[v] = u
            vis[v] = True

for u in reversed(order):
    if is_leaf[u]:
        continue
    sum_k, sum_b, sum_w = 0, 0, 0
    for edge in e[u]:
        v, w = edge[0], edge[1]
        if fa[u] != v:
            sum_k += k[v]
            sum_b += b[v]
        sum_w += w

    rev = pow(d[u] - sum_k, -1, mod)
    k[u] = rev
    b[u] = (sum_b + sum_w) * rev % mod

res = (b[0] % mod + mod) % mod
print(res)
