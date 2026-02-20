# Submission link: https://codeforces.com/gym/104855/submission/363691747
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        path = lst_lst(n)
        
        def f(x, y): return x * n + y
        
        for _ in range(m):
            u, v, c = GMI()
            path.append(u, f(c, v))
        
        vis = [[-2] * n for _ in range(2)]
        vis[0][0] = -1
        vis[1][0] = -1
        
        que = [0]
        
        for msk in que:
            u, time = divmod(msk, 2)
            
            for edge in path.iterate(u):
                c, v = divmod(edge, n)
                
                if vis[time][u] != c:
                    if vis[0][v] == -2:
                        vis[0][v] = c
                        que.append(2 * v)
                    elif vis[0][v] == c:
                        continue
                    elif vis[1][v] == -2:
                        vis[1][v] = c
                        que.append(2 * v + 1)
        
        outs.append(' '.join(str(i + 1) for i in range(n) if vis[0][i] != -2))
    
    print('\n'.join(outs))