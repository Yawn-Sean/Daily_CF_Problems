# Submission link: https://codeforces.com/gym/106677/submission/388961173
def main():
    outs = []
    
    while True:
        n, u, v = MII()
        
        if n == 0 and u == 0 and v == 0: break
        
        m = II()
        
        xs = [1, u, n]
        ys = [1, v, n]
        
        recs = []
        
        for _ in range(m):
            x1, x2, y1, y2 = MII()
            
            if x1 - 1 >= 1: xs.append(x1 - 1)
            xs.append(x1)
            xs.append(x2)
            if x2 + 1 <= n: xs.append(x2 + 1)
            
            if y1 - 1 >= 1: ys.append(y1 - 1)
            ys.append(y1)
            ys.append(y2)
            if y2 + 1 <= n: ys.append(y2 + 1)
            
            recs.append((x1, x2, y1, y2))
        
        xs = sorted(set(xs))
        ys = sorted(set(ys))
        
        N = len(xs)
        M = len(ys)
        
        grid = [[0] * M for _ in range(N)]
        
        for x1, x2, y1, y2 in recs:
            px1 = bisect.bisect_left(xs, x1)
            px2 = bisect.bisect_left(xs, x2 + 1)
            
            py1 = bisect.bisect_left(ys, y1)
            py2 = bisect.bisect_left(ys, y2 + 1)
            
            grid[px1][py1] += 1
            if px2 < N: grid[px2][py1] -= 1
            if py2 < M: grid[px1][py2] -= 1
            if px2 < N and py2 < M: grid[px2][py2] += 1
    
        for i in range(N):
            for j in range(1, M):
                grid[i][j] += grid[i][j - 1]
        
        for i in range(1, N):
            for j in range(M):
                grid[i][j] += grid[i - 1][j]
        
        dis = [[inf] * M for _ in range(N)]
        
        def f(x, y): return x * M + y
        
        def g(dis, x, y): return dis * N * M + f(x, y)
        
        sx = bisect.bisect_left(xs, u)
        sy = bisect.bisect_left(ys, v)
        
        dis[sx][sy] = 0
        
        pq = [g(0, sx, sy)]
        
        while pq:
            msk = heappop(pq)
            d, msk = divmod(msk, N * M)
            x, y = divmod(msk, M)
            
            if dis[x][y] == d:
                if x and grid[x - 1][y] == 0:
                    nd = d + xs[x] - xs[x - 1]
                    if dis[x - 1][y] > nd:
                        dis[x - 1][y] = nd
                        heappush(pq, g(dis[x - 1][y], x - 1, y))
    
                if x + 1 < N and grid[x + 1][y] == 0:
                    nd = d + xs[x + 1] - xs[x]
                    if dis[x + 1][y] > nd:
                        dis[x + 1][y] = nd
                        heappush(pq, g(dis[x + 1][y], x + 1, y))
                
                if y and grid[x][y - 1] == 0:
                    nd = d + ys[y] - ys[y - 1]
                    if dis[x][y - 1] > nd:
                        dis[x][y - 1] = nd
                        heappush(pq, g(dis[x][y - 1], x, y - 1))
                
                if y + 1 < M and grid[x][y + 1] == 0:
                    nd = d + ys[y + 1] - ys[y]
                    if dis[x][y + 1] > nd:
                        dis[x][y + 1] = nd
                        heappush(pq, g(dis[x][y + 1], x, y + 1))
        
        q = II()
        
        for _ in range(q):
            x, y = MII()
            pxl = bisect.bisect_right(xs, x) - 1
            pyl = bisect.bisect_right(ys, y) - 1
            
            pxr = pxl + 1 if pxl + 1 < N and grid[pxl + 1][pyl] == 0 else pxl
            pyr = pyl + 1 if pyl + 1 < M and grid[pxl][pyl + 1] == 0 else pyl
    
            ans = inf
            for i in range(pxl, pxr + 1):
                for j in range(pyl, pyr + 1):
                    if grid[i][j] == 0:
                        ans = fmin(ans, dis[i][j] + abs(xs[i] - x) + abs(ys[j] - y))
            
            outs.append(str(ans) if ans < inf else 'no')
    
    print('\n'.join(outs))