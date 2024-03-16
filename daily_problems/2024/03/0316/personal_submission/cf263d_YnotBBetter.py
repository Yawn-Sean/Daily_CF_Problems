import sys
input = lambda: sys.stdin.readline().strip()

# 为了尽可能得到最大的环，dfs时必定要优先选择没有访问过的点
# 当必须要形成环时，说明在某个时刻某个点的所有邻居节点都已经访问过
# 已知这个点至少连接到k个其他节点，意味着必须要形成环的时候，已访问的节点集合至少为k+1，即当前点和所有邻居点，则环的长度至少为k+1
# 因此，dfs的过程是不需要回溯的

n, m, k = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u-1].append(v-1)
    graph[v-1].append(u-1)

ans = [1]
seen = [False] * n
seen[0] = True

stack = [0]
while True:
    cur = stack.pop()
    for nxt in graph[cur]:
        if not seen[nxt]:
            ans.append(nxt + 1)
            seen[nxt] = True
            stack.append(nxt)
            break
    else:
        break

node_idx = {v: idx for idx, v in enumerate(ans)}
min_idx = min([node_idx[nxt+1] for nxt in graph[ans[-1]-1]])

print(len(ans[min_idx:]))
print(*ans[min_idx:])
