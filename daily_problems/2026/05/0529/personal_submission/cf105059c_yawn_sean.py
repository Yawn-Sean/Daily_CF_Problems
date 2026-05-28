# Submission link: https://codeforces.com/gym/105059/submission/376348213
def main():
    n, m, g = MII()
    
    if g > 2: print(0)
    else:
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        dis = [-1] * n
        
        que = [0]
        dis[0] = 0
        
        flg = True
        
        for u in que:
            for v in path[u]:
                if dis[v] == -1:
                    dis[v] = dis[u] ^ 1
                    que.append(v)
                elif dis[u] == dis[v]:
                    flg = False
        
        print(1 if flg and dis[-1] else 0)