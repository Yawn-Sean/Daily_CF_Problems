# 快读板子
import sys
from collections import defaultdict

RI = lambda: int(sys.stdin.readline().strip())
RII = lambda: map(int, sys.stdin.readline().strip().split())

n = RI()
edges = []
g = defaultdict(list)
for _ in range(n - 1):
    a, b, l = RII()
    g[a - 1].append((b - 1, l))
    g[b - 1].append((a - 1, l))
    edges.append([a - 1, b - 1, l])  # 后面要反复修改l，用数组

#size = [0] * n
#fa = [-1] * n

# 计算u的子节点数量
# def dfs(u, f):
#     fa[u] = f
#     size[u] = 1
#     for v, _ in g[u]:
#         if v != f:
#             dfs(v, u)
#             size[u] += size[v]
#
#
# dfs(0, -1)

# dfs递归过不去，改递推
order = []
st = [0]
size = [1] * n
fa = [-1] * n

while st:
    u = st.pop()
    for v, _ in g[u]:
        if v and fa[v] == -1: # 注意0不能改
            fa[v] = u
            st.append(v)
    order.append(u)

for u in reversed(order):
    if u:
        v = fa[u]
        size[v] += size[u]


def work(x, y, v):
    if fa[y] == x:
        x, y = y, x
    sx = size[x]
    sy = n - sx
    return v * ((sx * (sx - 1) * sy / 2) + (sy * (sy - 1) * sx / 2))


ans = 0
for a, b, l in edges:
    ans += 2 * work(a, b, l)

m = RI()
for _ in range(m):
    r, w = RII()
    a, b, l = edges[r - 1]
    ans -= 2 * work(a, b, l)
    edges[r - 1][2] = w  # 记得修改l
    ans += 2 * work(a, b, w)
    print(ans / (n * (n - 1) * (n - 2) / 6))
