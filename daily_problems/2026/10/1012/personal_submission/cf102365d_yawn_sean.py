# Submission link: https://codeforces.com/gym/102365/submission/394101857
def main():
    n, J = MII()
    upward = LII()
    downward = LII()
    
    dis = [inf] * (2 * n + 1)
    vis = [0] * (2 * n + 1)
    
    dis[n] = 0
    vis[n] = 1
    
    chosen = n
    
    for _ in range(2 * n):
        for i in range(J):
            u = chosen + i + 1
            if u <= 2 * n and not vis[u]:
                dis[u] = fmin(dis[u], dis[chosen] + upward[i])
            
            u = chosen - i - 1
            if u >= 0 and not vis[u]:
                dis[u] = fmin(dis[u], dis[chosen] + downward[i])
        
        nchosen = -1
        for u in range(2 * n + 1):
            if not vis[u] and (nchosen == -1 or dis[u] < dis[nchosen]):
                nchosen = u
        
        chosen = nchosen
        vis[chosen] = 1
    
    dp_l = [inf] * (n + 1)
    dp_r = [inf] * (n + 1)
    
    dp_l[1] = 0
    dp_r[1] = 0
    
    for i in range(2, n + 1):
        for j in range(1, i):
            v = fmax(dp_r[j], dp_l[i - j])
            dp_l[i] = fmin(dp_l[i], v + dis[n + j])
            dp_r[i] = fmin(dp_r[i], v + dis[n - (i - j)])
    
    print(dp_l[n])
