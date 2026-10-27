# Submission link: https://codeforces.com/gym/106785/submission/396089724
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        k -= 1
        
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        def get_dis(u):
            que = [u]
            dis = [-1] * n
            dis[u] = 0
            
            for u in que:
                for v in path[u]:
                    if dis[v] == -1:
                        dis[v] = dis[u] + 1
                        que.append(v)
            
            return dis
        
        d0 = get_dis(0)
        
        rt1 = d0.index(max(d0))
        d1 = get_dis(rt1)
        
        rt2 = d1.index(max(d1))
        d2 = get_dis(rt2)
        
        mx = max(d1)
        
        outs.append('Bob' if d1[k] == d2[k] and d1[k] + d2[k] == mx else 'Alice')
    
    print('\n'.join(map(str, outs)))