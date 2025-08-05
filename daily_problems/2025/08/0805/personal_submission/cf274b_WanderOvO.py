"""
如果树退化成一条链，怎么做
从尾端到头端处理，顺便统计加和减过多少次了即可
"""
import queue

n = int(input())
e = [[] for _ in range(n + 1)]
for i in range(n - 1):
    u, v = map(int, input().split())
    e[u].append(v)
    e[v].append(u)

val = [0] + list(map(int, input().split()))
add_cnt = [0 for _ in range(n + 1)]
sub_cnt = [0 for _ in range(n + 1)]

q = queue.Queue()
q.put(1)
vis = [False for _ in range(n + 1)]
vis[1] = True
order = []
while not q.empty():
    u = q.get()
    order.append(u)
    for v in e[u]:
        if not vis[v]:
            vis[v] = True
            q.put(v)

reversed_order = order[::-1]
vis = [False for _ in range(n + 1)]
for u in reversed_order:
    vis[u] = True
    for v in e[u]:
        if vis[v]:
            add_cnt[u] = max(add_cnt[u], add_cnt[v])
            sub_cnt[u] = max(sub_cnt[u], sub_cnt[v])
    val[u] += add_cnt[u]
    val[u] -= sub_cnt[u]
    if val[u] > 0:
        sub_cnt[u] += val[u]
    else:
        add_cnt[u] -= val[u]

print(add_cnt[1] + sub_cnt[1])
