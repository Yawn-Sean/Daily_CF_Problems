# Submission link: https://codeforces.com/gym/106732/submission/392897138
def main():
    n = II()
    nums = LII()
    
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for msk in path[u]:
            w, v = divmod(msk, n)
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    dp0 = [0] * n
    dp1 = [inf] * n
    tot = [0] * n
    
    for u in reversed(que):
        v0 = []
        v1 = []
        ws = []
        
        for msk in path[u]:
            w, v = divmod(msk, n)
            if parent[v] == u:
                v0.append(fmax(w + dp0[v], 2 * w + tot[v]))
                v1.append(w + dp1[v])
                ws.append(2 * w + tot[v])
                tot[u] += 2 * w + tot[v]
        
        k = len(v0)
        
        if k == 0:
            dp0[u] = 0
            dp1[u] = 0
        else:
            gain = [i for i in range(k) if ws[i] <= 0]
            cost = [i for i in range(k) if ws[i] > 0]
            gain.sort(key=lambda x: v0[x])
            cost.sort(key=lambda x: ws[x] - v0[x])
            st_range = gain + cost
            
            suff = [0] * (k + 1)
            for idx in range(k - 1, -1, -1):
                i = st_range[idx]
                suff[idx] = fmax(suff[idx + 1] + ws[i], v0[i])
            
            cur_w = 0
            for idx in range(k):
                i = st_range[idx]
                dp1[u] = fmin(dp1[u], max(dp0[u], suff[idx + 1] + cur_w, tot[u] - ws[i] + v1[i]))
                dp0[u] = fmax(dp0[u], v0[i] + cur_w)
                cur_w += ws[i]
        
        dp0[u] = fmax(dp0[u] - nums[u], 0)
        dp1[u] = fmax(dp1[u] - nums[u], 0)
        tot[u] -= nums[u]
    
    print(dp1[0])