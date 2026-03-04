# Submission link: https://codeforces.com/gym/106404/submission/365342749
def main(): 
    t = II()
    outs = []
    
    inf = 11 * 10 ** 8
    
    for _ in range(t):
        n, m = MII()
        nums = LII()
        
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = MII()
            u -= 1
            v -= 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        pq = [nums[i] * n + i for i in range(n)]
        
        while pq:
            d, u = divmod(heappop(pq), n)
            if nums[u] == d:
                for msk in path[u]:
                    nd, v = divmod(msk, n)
                    if nd + d < nums[v]:
                        nums[v] = nd + d
                        heappush(pq, nums[v] * n + v)
        
        dis = [inf] * n
        dis[0] = 0
        
        pq = [0]
        
        while pq:
            d, u = divmod(heappop(pq), n)
            if dis[u] == d:
                for msk in path[u]:
                    nd, v = divmod(msk, n)
                    if nd + d < dis[v] and nd + d <= nums[v]:
                        dis[v] = nd + d
                        heappush(pq, dis[v] * n + v)
        
        outs.append('YES' if dis[n - 1] < inf else 'NO')
    
    print('\n'.join(outs))
