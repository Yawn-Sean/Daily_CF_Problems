# Submission link: https://codeforces.com/gym/106627/submission/383516586
def main():
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n, m = MII()
        path = [[] for _ in range(n)]
        
        uf = UnionFind(n)
        cur = 1
        
        for _ in range(m):
            u, v = GMI()
            if uf.merge(u, v):
                path[u].append(cur * n + v)
                path[v].append(cur * n + u)
            cur = cur * 2 % mod
        
        dis = [-1] * n
        dis[0] = 0
        
        que = [0]
        
        for u in que:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if dis[v] == -1:
                    dis[v] = (dis[u] + w) % mod
                    que.append(v)
        
        outs.append(' '.join(map(str, dis[1:])))
    
    print('\n'.join(outs))