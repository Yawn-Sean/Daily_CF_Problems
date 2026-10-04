# Submission link: https://codeforces.com/gym/101047/submission/393142006
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, k = MII()
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = MII()
            u -= 1
            v -= 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        dis = [inf] * n
        dis[n - 1] = 0
        
        pq = [n - 1]
        
        while pq:
            d, u = divmod(heappop(pq), n)
            if dis[u] == d:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    if dis[v] > dis[u] + w:
                        dis[v] = dis[u] + w
                        heappush(pq, dis[v] * n + v)
        
        tmp = sorted(dis)
        
        ans = n * k
        cur = 0
        
        for i in range(1, n):
            cur += tmp[i - 1]
            res = (cur + k * n) / i
            if res <= tmp[i]:
                ans = fmin(ans, res)
        
        ans = fmin(ans, dis[0])
        outs.append(f'{ans:.10f}')
    
    print('\n'.join(outs))