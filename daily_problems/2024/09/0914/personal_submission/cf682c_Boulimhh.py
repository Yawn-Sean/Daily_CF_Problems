"""
DFS 不太熟练, 所以这题只能读代码了 . 

先建树, 建完树再从根开始遍历, 把符合的节点加入, 统计符合要求的节点数 .

用n 减去符合的, 剩下就是需要去掉的悲伤节点.

"""
#python代码:
n = int(input())
a = list(map(int, input().split()))
edges = [0]
tree = [[] for _ in range(n)]

for i in range(1, n):
    p, c = map(int, input().split())
    edges.append(c)
    tree[p - 1].append(i)
q = [0]
f = [0] * n
ans = 0
while q:
    u = q.pop()
    ans += 1
    for v in tree[u]:
        f[v] = max(0, f[u]) + edges[v]
        if f[v] <= a[v]:
            q.append(v)
print(n - ans)
