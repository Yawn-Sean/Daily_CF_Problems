from collections import deque

n = int(input())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    g[u].append(v)
    g[v].append(u)

# bfs
st = deque([0])
parent = [-1] * n
col = tmp = 0
order = []
while st:
    l = len(st)
    for _ in range(l):
        fa = st.popleft()  # 不是 pop !!!
        for son in g[fa]:
            if son != parent[fa]:
                parent[son] = fa
                st.append(son)
                order.append(son)
    col += l if tmp else 0
    tmp ^= 1

# 树形dp
size = [1] * n
for u in order[::-1]:
    size[parent[u]] += size[u]
size[0] = 0

ans = 0
for x in size:
    ans += x * (n - x)

print((ans + col * (n - col)) // 2) 
