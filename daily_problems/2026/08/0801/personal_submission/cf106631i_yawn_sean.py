# Submission link: https://codeforces.com/gym/106631/submission/384941791
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, a, b = MII()
        a -= 1
        b -= 1
        
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
            
        dis = [-1] * n
        dis[b] = 0
        
        vis_times = [0] * n
        vis_times[b] = 2
        
        que = [b]
        for u in que:
            for v in path[u]:
                vis_times[v] += 1
                if vis_times[v] == 2:
                    dis[v] = dis[u] + 1
                    que.append(v)
        
        outs.append(dis[a])
    
    print('\n'.join(map(str, outs)))