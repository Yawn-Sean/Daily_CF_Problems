'''
https://codeforces.com/gym/106015/submission/350585730
'''
def solve(n: int, m: int, edges: list[list[int]]) -> bool: 
    uni = UnionFind(n)
    si = sorted(range(m), key=lambda i: edges[i][2])
    
    path = [[] for _ in range(n)]
    b = [0] * m
    
    for i in si:
        u, v, w = edges[i]
        if uni.union(u, v):
            b[i] = 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
    
    global ra
    init_lca(n, m, edges, path)
    
    for i in range(m):
        if not b[i]:
            u = u
            v = v
            l = lca(u, v)
            if ra[u] + ra[v] - 2 * ra[l] > w:
                return False
    return True

