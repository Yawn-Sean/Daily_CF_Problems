# Submission link: https://codeforces.com/contest/1044/submission/300905839
def main():
    t = II()
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        k1 = II()
        nodes1 = LGMI()
        
        k2 = II()
        nodes2 = LGMI()
        
        vis1 = [0] * n
        for u in nodes1:
            vis1[u] = 1
        
        vis2 = [0] * n
        for u in nodes2:
            vis2[u] = 1
        
        print('B', nodes2[0] + 1, flush=True)
        rt = II() - 1
        
        if vis1[rt]:
            print('C', rt + 1, flush=True)
        
        else:
            vis = [0] * n
            vis[rt] = 1
            
            que = [0] * n
            que[0] = rt
            
            l, r = 0, 1
            chosen = -1
            
            while l < r:
                u = que[l]
                l += 1
                
                if vis1[u]:
                    chosen = u
                    break
                
                for v in path[u]:
                    if vis[v] == 0:
                        vis[v] = 1
                        que[r] = v
                        r += 1
            
            print('A', chosen + 1, flush=True)
            u = II() - 1
            print('C', chosen + 1 if vis2[u] else -1, flush=True)