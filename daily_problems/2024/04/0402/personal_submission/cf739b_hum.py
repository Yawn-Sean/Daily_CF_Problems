import sys
from bisect import bisect_left

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
nums = list(map(int, input().split()))
graph = [[] for _ in range(n)]
parent = [-1] * n

for i in range(1, n):
  p, w = map(int, input().split())
  p -= 1
  graph[p].append((i, w))
  parent[i] = p

res = [0] * (n + 1)
dis = [0] * n

cur_path = []
cur_dis = []

stack = [0]
dfs_order = []

while stack:
  u = stack.pop()
  if u >= 0:
    cur_path.append(u)
    cur_dis.append(dis[u])
    idx = bisect_left(cur_dis, dis[u] - nums[u])
    # p[0] = -1 -> res[n]
    res[parent[u]] += 1
    res[parent[cur_path[idx]]] -= 1
    stack.append(~u)
    dfs_order.append(u)
    for v, w in graph[u]:
      stack.append(v)
      dis[v] = dis[u] + w
  else:
    cur_path.pop()
    cur_dis.pop()

for i in reversed(dfs_order):
  if i:
    res[parent[i]] += res[i]

print(*res[:-1])
