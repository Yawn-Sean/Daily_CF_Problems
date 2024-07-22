n, m, s, t = MII()
s -= 1
t -= 1
roads = [LGMI() for _ in range(m)]
child = [set() for _ in range(n + 1)]
for a, b in roads:
    child[a].add(b)
    child[b].add(a)

nodes = deque([(0, s)])
sdis = [inf] * n
sdis[s] = 0
while nodes:
    dis, node = nodes.popleft()
    if dis > sdis[node]:
        continue
    for nxt in child[node]:
        if sdis[nxt] > dis + 1:
            sdis[nxt] = dis + 1
            nodes.append((dis + 1, nxt))

tdis = [inf] * n
tdis[t] = 0
nodes = deque([(0, t)])
while nodes:
    dis, node = nodes.popleft()
    if dis > tdis[node]:
        continue
    for nxt in child[node]:
        if tdis[nxt] > dis + 1:
            tdis[nxt] = dis + 1
            nodes.append((dis + 1, nxt))
res = 0
path_len = sdis[t]
for i in range(n):
    for j in range(i + 1, n):
        if i != j and j not in child[i]:
            if sdis[i] + tdis[j] + 1 >= path_len:
                res += 1
print(res)
