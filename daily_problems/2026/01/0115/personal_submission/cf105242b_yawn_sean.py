# Submission link: https://codeforces.com/gym/105242/submission/357784870
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        flg = True
        rt = -1
        for i in range(n):
            if len(path[i]) > 3:
                flg = False
            elif len(path[i]) == 3:
                rt = i
        
        if not flg: outs.append('NO')
        elif rt != -1:
            parent = [-1] * n
            que = [rt]
            
            for u in que:
                for v in path[u]:
                    if parent[u] != v:
                        parent[v] = u
                        que.append(v)
            
            vis = [0] * n
            
            for i in range(n):
                if len(path[i]) == 3:
                    cur = i
                    while cur >= 0 and not vis[cur]:
                        vis[cur] = 1
                        cur = parent[cur]
            
            for i in range(n):
                v = 0
                for j in path[i]:
                    v += vis[j]
                if v >= 3: flg = False
            
            outs.append('YES' if flg else 'NO')
            
        else: outs.append('YES')
    
    print('\n'.join(outs))