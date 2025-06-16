n, q = MII()
parent = [-1] + LGMI()
path = [[] for _ in range(n)]

for i in range(1, n):
    path[parent[i]].append(i)
for i in range(n):
    path[i].reverse()
order = []
pos = [-1] * n

stk = [0]
while stk:
    u = stk.pop()
    pos[u] = len(order)
    order.append(u)
    
    for v in path[u]:
        stk.append(v)
        
size = [1] * n
for i in reversed(order):
    if parent[i] != -1:
        size[parent[i]] += size[i]
outs = []
for _ in range(q):
    u, k = GMI()
    outs.append(order[pos[u] + k] + 1 if k < size[u] else -1)

print('\n'.join(map(str, outs)))
