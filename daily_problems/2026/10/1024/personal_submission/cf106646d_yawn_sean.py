# Submission link: https://codeforces.com/gym/106646/submission/395688296
def main():
    n, h = MII()
    
    ans = 0
    
    lefts = [[] for _ in range(n)]
    rights = [[] for _ in range(n)]
    
    for i in range(n):
        k = II()
        polygon = [tuple(MII()) for _ in range(k)]
        
        pt = min(polygon, key=lambda x: (x[1], x[0]))
        idx = polygon.index(pt)
        pts = []
        
        while True:
            pts.append(polygon[idx])
            if polygon[idx][1] == h: break
            idx = (idx - 1) % k
        
        lefts[i] = pts
        
        pt = max(polygon, key=lambda x: (x[1], x[0]))
        idx = polygon.index(pt)
        pts = []
        
        while True:
            pts.append(polygon[idx])
            if polygon[idx][1] == 0: break
            idx = (idx - 1) % k
        
        pts.reverse()
        rights[i] = pts
        
        ans += max(polygon)[0] - min(polygon)[0]
    
    grid = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if i != j:
                left = rights[i]
                right = lefts[j]
                
                base = min(right)[0] - max(left)[0]
                real = inf
                
                pt = 0
                
                for idx in range(len(left)):
                    while pt + 1 < len(right) and right[pt + 1][1] < left[idx][1]:
                        pt += 1
                    
                    x, y = left[idx]
                    x1, y1 = right[pt]
                    x2, y2 = right[pt + 1]
                    
                    cur_x = (x1 * (y2 - y1) + (x2 - x1) * (y - y1)) / (y2 - y1)
                    real = fmin(real, cur_x - x)
                
                pt = 0
                
                for idx in range(len(right)):
                    while pt + 1 < len(left) and left[pt + 1][1] < right[idx][1]:
                        pt += 1
                    
                    x, y = right[idx]
                    x1, y1 = left[pt]
                    x2, y2 = left[pt + 1]
                    
                    cur_x = (x1 * (y2 - y1) + (x2 - x1) * (y - y1)) / (y2 - y1)
                    real = fmin(real, x - cur_x)
                
                grid[i][j] = real - base
    
    dp = [[0] * (1 << n) for _ in range(n)]
    
    for i in range(1 << n):
        for j in range(n):
            if i >> j & 1:
                for k in range(n):
                    if i >> k & 1: continue
                    ni = i | (1 << k)
                    dp[k][ni] = fmax(dp[k][ni], dp[j][i] + grid[j][k])
    
    print(ans - max(x[-1] for x in dp))