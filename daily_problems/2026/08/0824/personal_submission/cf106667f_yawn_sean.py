# Submission link: https://codeforces.com/gym/106667/submission/388147115
def main():
    n, h = MII()
    
    if n == 0: print(h)
    else:
        xs = []
        ys = []
        rs = []
    
        for _ in range(n):
            x, y, r = MII()
            xs.append(x)
            ys.append(y)
            rs.append(r)
    
        dis = [fmax(ys[i] - rs[i], 0) for i in range(n)]
        vis = [0] * n
    
        def f(i, j):
            return math.sqrt((xs[i] - xs[j]) * (xs[i] - xs[j]) + (ys[i] - ys[j]) * (ys[i] - ys[j]))
    
        for _ in range(n):
            chosen = -1
            for idx in range(n):
                if vis[idx] == 0 and (chosen == -1 or dis[idx] < dis[chosen]):
                    chosen = idx
            
            vis[chosen] = 1
            for i in range(n):
                dis[i] = fmin(dis[i], dis[chosen] + fmax(0, f(chosen, i) - rs[chosen] - rs[i]))
    
        ans = min(dis[i] + fmax(0, h - ys[i] - rs[i]) for i in range(n))
        print(f'{ans:.15f}')