# Submission link: https://codeforces.com/gym/105327/submission/361256109
def main(): 
    n, m = MII()
    uf = UnionFind(n + m)
    
    path = [[] for _ in range(n + m)]
    
    for i in range(n):
        _, *idxs = MII()
        
        for idx in idxs:
            idx -= 1
            if uf.merge(idx, m + i):
                path[idx].append(m + i)
                path[m + i].append(idx)
    
    parent = [-1] * (n + m)
    depth = [0] * (n + m)
    
    for i in range(n + m):
        if parent[i] == -1:
            que = [i]
            for u in que:
                for v in path[u]:
                    if parent[u] != v:
                        parent[v] = u
                        depth[v] = depth[u] + 1
                        que.append(v)
    
    q = II()
    outs = []
    
    for _ in range(q):
        u, v = GMI()
        
        if uf.find(u) != uf.find(v): outs.append('-1')
        else:
            path_u = [u]
            path_v = [v]
            
            while path_u[-1] != path_v[-1]:
                if depth[path_u[-1]] > depth[path_v[-1]]:
                    path_u.append(parent[path_u[-1]])
                else:
                    path_v.append(parent[path_v[-1]])
            
            path_v.reverse()
            path_u.extend(path_v[1:])
            
            outs.append(str(len(path_u) // 2 + 1))
            outs.append(' '.join(str(x + 1) if x < m else str(x - m + 1) for x in path_u))
    
    print('\n'.join(outs))
