# Submission link: https://codeforces.com/contest/231/submission/272625602
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    union = UnionFind(n)

    mod = 10 ** 9 + 7

    pow2 = [1] * (n + 1)
    for i in range(n):
        pow2[i+1] = pow2[i] * 2 % mod

    edges = []

    for _ in range(m):
        u, v = GMI()
        if union.find(u) != union.find(v):
            union.merge(u, v)
            path[u].append(v)
            path[v].append(u)
        else:
            edges.append((u, v))

    parent = [-1] * n
    depth = [0] * n
    stack = [0]
    order = []
    while stack:
        u = stack.pop()
        order.append(u)
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                depth[v] = depth[u] + 1
                stack.append(v)

    size = [1] * n

    for i in reversed(order):
        if parent[i] >= 0:
            size[parent[i]] += size[i]

    col = list(range(n))
    notes = [0] * n

    for u, v in edges:
        if depth[u] < depth[v]:
            u, v = v, u
        
        cu, cv = u, v
        while depth[cu] > depth[cv]:
            cu = parent[cu]
        
        while cu != cv:
            cu = parent[cu]
            cv = parent[cv]
        
        while u != cu:
            nu = parent[u]
            col[u] = cu
            u = nu
        
        while v != cv:
            nv = parent[v]
            col[v] = cu
            v = nv
        
        notes[cu] = 1

    heads = list(range(n))
    for i in order:
        chosen = -1
        for j in path[i]:
            if parent[j] == i:
                if chosen == -1 or size[j] > size[chosen]:
                    chosen = j
                notes[j] += notes[i]
        if chosen != -1:
            heads[chosen] = heads[i]

    q = II()
    outs = []

    for _ in range(q):
        u, v = GMI()
        u = col[u]
        v = col[v]
        ans = notes[u] + notes[v]
        while heads[u] != heads[v]:
            if depth[heads[u]] > depth[heads[v]]:
                u = parent[heads[u]]
            else:
                v = parent[heads[v]]
        l = u if depth[u] < depth[v] else v
        l = col[l]
        ans -= notes[l]
        if parent[l] >= 0: ans -= notes[parent[l]]
        outs.append(pow2[ans])

    print(*outs, sep='\n')