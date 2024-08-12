input = sys.stdin.read
data = input().split()

index = 0
n = int(data[index])
index += 1
m = int(data[index])
index += 1

graph = defaultdict(list)
flow = [0] * (n + 1)
edges = []

for _ in range(m):
    v = int(data[index])
    index += 1
    w = int(data[index])
    index += 1
    c = int(data[index])
    index += 1
    graph[v].append((w, len(edges), 0, c))
    graph[w].append((v, len(edges), 1, c))
    flow[v] += c
    flow[w] += c
    edges.append((v, w, c))

for i in range(1, n + 1):
    flow[i] //= 2

ans = [-1] * m
queue = deque([1])

while queue:
    v = queue.popleft()
    for w, i, d, f in graph[v]:
        if ans[i] == -1:
            ans[i] = d
            flow[w] -= f
            if w != n and flow[w] == 0:
                queue.append(w)

print(*ans, sep='\n')
