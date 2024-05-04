# Submission link: https://codeforces.com/contest/1817/submission/258804078
def main():
    n, m = MII()
    
    path = [[] for _ in range(n)]
    for i in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    edges = []
    for i in range(n):
        if len(path[i]) >= 4:
            vis = [-1] * n
            parent = [-1] * n
            vis[i] = i
            
            dq = deque([j for j in path[i]])
            for u in dq:
                vis[u] = u
                parent[u] = i
            
            while dq:
                u = dq.popleft()
                for v in path[u]:
                    if vis[v] == -1:
                        vis[v] = vis[u]
                        parent[v] = u
                        dq.append(v)
            
            for u in range(n):
                for v in path[u]:
                    if u != i and v != i and vis[u] != -1 and vis[v] != -1 and vis[u] != vis[v]:
                        edges.append((u, v))
                        
                        while u != i:
                            vis[u] = -1
                            edges.append((u, parent[u]))
                            u = parent[u]
                        while v != i:
                            vis[v] = -1
                            edges.append((v, parent[v]))
                            v = parent[v]
                        
                        cnt = 0
                        for j in path[i]:
                            if vis[j] != -1:
                                cnt += 1
                                edges.append((i, j))
                                if cnt == 2: break
                        break
                if len(edges): break
            if len(edges): break
    
    if len(edges) == 0: outs.append('NO')
    else:
        outs.append('YES')
        outs.append(str(len(edges)))
        for u, v in edges:
            outs.append(f'{u + 1} {v + 1}')