# Submission link: https://codeforces.com/contest/730/submission/333650863
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    w = II()
    cs = []
    ks = []
    ps = []
    
    for i in range(w):
        c, k, p = MII()
        c -= 1
        cs.append(c)
        ks.append(k)
        ps.append(p)
    
    st_range = sorted(range(w), key=lambda x: ps[x])
    
    q = II()
    dis = [n] * n
    outs = []
    
    for _ in range(q):
        g, r, a = MII()
        g -= 1
        
        que = [g]
        dis[g] = 0
        
        for u in que:
            for v in path[u]:
                if dis[v] == n:
                    dis[v] = dis[u] + 1
                    que.append(v)
        
        left, right = 0, n - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            total = 0
            cur = r
            
            for i in st_range:
                if dis[cs[i]] <= mid:
                    val = fmin(cur, ks[i])
                    cur -= val
                    total += val * ps[i]
            
            if total <= a and cur == 0:
                right = mid - 1
            else:
                left = mid + 1
        
        outs.append(left if left < n else -1)
        
        for i in range(n):
            dis[i] = n
    
    print('\n'.join(map(str, outs)))