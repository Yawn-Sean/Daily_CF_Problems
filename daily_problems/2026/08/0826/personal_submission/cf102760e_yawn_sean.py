# Submission link: https://codeforces.com/gym/102760/submission/388307322
def main():
    n, m = MII()
    tag = LII()
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    vis = [-1] * n
    
    w0 = [0] * n
    w1 = [0] * n
    
    for i in range(n):
        if vis[i] == -1:
            que = [i]
            flg = True
            
            vis[i] = 0
            for u in que:
                for v in path[u]:
                    if vis[v] == -1:
                        vis[v] = vis[u] ^ 1
                        que.append(v)
                    elif vis[v] == vis[u]:
                        flg = False
    
            if flg:
                v0 = inf
                v1 = inf
                
                for u in que:
                    if vis[u] == 0: v0 = fmin(v0, tag[u])
                    else: v1 = fmin(v1, tag[u])
    
                for u in que:
                    if vis[u] == 0:
                        w0[u] = v0
                        w1[u] = v1
                    else:
                        w1[u] = v0
                        w0[u] = v1
            
            else:
                v = inf
                
                for u in que:
                    v = fmin(v, tag[u])
                
                for u in que:
                    w0[u] = v
                    w1[u] = v
    
    def count_pairs(nums):
        ans = 0
        cnt = [0] * (n + 1)
        
        for x in nums:
            ans += cnt[x]
            cnt[x] += 1
        
        return ans
    
    print(fmax(count_pairs(w0), count_pairs(w1)))