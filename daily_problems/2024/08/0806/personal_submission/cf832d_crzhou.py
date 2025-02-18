def dfs(root):
    stack = [(root, 0)]
    while stack:
        node, parent = stack.pop()
        depth[node] = depth[parent] + 1
        up[node][0] = parent
        for i in range(1, max_depth):
            up[node][i] = up[up[node][i-1]][i-1]
        for neighbor in tree[node]:
            if neighbor != parent:
                stack.append((neighbor, node))

def lca(u, v):
    if depth[u] < depth[v]:
        u, v = v, u
    diff = depth[u] - depth[v]
    for i in range(max_depth):
        if (diff >> i) & 1:
            u = up[u][i]
    if u == v:
        return u
    for i in range(max_depth-1, -1, -1):
        if up[u][i] != up[v][i]:
            u = up[u][i]
            v = up[v][i]
    return up[u][0]

def dist(u, v):
    ancestor = lca(u, v)
    return depth[u] + depth[v] - 2 * depth[ancestor]

n = int(data[0])
q = int(data[1])

tree = defaultdict(list)
depth = [0] * (n + 1)
max_depth = int(math.log2(n)) + 1
up = defaultdict(lambda: [0] * max_depth)

index = 2
for i in range(2, n + 1):
    parent = int(data[index])
    tree[parent].append(i)
    tree[i].append(parent)
    index += 1

dfs(1)

result = []
for _ in range(q):
    a = int(data[index])
    b = int(data[index + 1])
    c = int(data[index + 2])
    index += 3

    ab = dist(a, b)
    bc = dist(b, c)
    ca = dist(c, a)

    max_dist = max(ab + bc - ca, ab + ca - bc, bc + ca - ab) // 2 + 1
    
    result.append(str(max_dist))

print("\n".join(result))
