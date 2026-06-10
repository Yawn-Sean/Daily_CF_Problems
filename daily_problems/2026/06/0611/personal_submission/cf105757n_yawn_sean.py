# Submission link: https://codeforces.com/gym/105757/submission/378047606
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = MII()
            path[u].append(v)
            path[v].append(u)
        
        parent = [-1] * n
        que = [0]
        
        for u in que:
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    que.append(v)
        
        vis = [0] * n
        vis[0] = 1
        
        degs = [0] * n
        ans = 0
        flg = True
        
        for i in range(1, n):
            cur = i
            while not vis[cur]:
                vis[cur] = 1
                degs[cur] += 1
                degs[parent[cur]] += 1
                cur = parent[cur]
                if degs[cur] > 2:
                    flg = False
            if flg: ans = i
        
        out = [0] * (n - 1)
        out[0] = ans + 1
        
        for i in range(1, len(path[0])):
            out[i] = 1
        
        outs.append(' '.join(map(str, out)))
    
    print('\n'.join(outs))