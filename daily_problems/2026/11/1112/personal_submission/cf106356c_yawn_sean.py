# Submission link: https://codeforces.com/gym/106356/submission/398103473
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        p = LII()
        
        path = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            u, v = MII()
            path[u].append(v)
            path[v].append(u)
        
        ops = []
        
        for i in range(n - 1):
            rt = p[i]
            parent = [-1] * (n + 1)
            
            que = [rt]
            
            for u in que:
                for v in path[u]:
                    if parent[u] != v:
                        parent[v] = u
                        que.append(v)
    
            a = p[i + 1]
            b = parent[a]
            
            path[a].remove(b)
            path[b].remove(a)
            
            while b != rt:
                ops.append(f'{a} {b} {parent[b]}')
                b = parent[b]
            
            path[a].append(rt)
            path[rt].append(a)
        
        outs.append(f'{len(ops)}')
        if ops: outs.append('\n'.join(ops))
    
    print('\n'.join(outs))