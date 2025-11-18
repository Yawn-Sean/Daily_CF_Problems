# Submission link: https://codeforces.com/gym/106007/submission/349551851
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        s = [int(c) for c in I()]
        
        path = [[] for _ in range(n)]
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        queries = [II() - 1 for _ in range(q)]
        
        rt = queries[0]
        parent = [-1] * n
        
        que = [rt]
        
        for u in que:
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    que.append(v)
        
        cols = [0] * n
        cnt = n
        
        for i in range(n):
            if s[i] == 0:
                u = i
                while u >= 0 and cols[u] == 0:
                    cols[u] = 1
                    cnt -= 1
                    u = parent[u]
        
        total = sum(s)
        
        for u in queries:
            if s[u]:
                s[u] = 0
                total -= 1
            
            while u >= 0 and cols[u] == 0:
                cols[u] = 1
                cnt -= 1
                u = parent[u]
            
            outs.append(cnt * (cnt + 1) // 2 + cnt * (total - cnt))
    
    print('\n'.join(map(str, outs)))