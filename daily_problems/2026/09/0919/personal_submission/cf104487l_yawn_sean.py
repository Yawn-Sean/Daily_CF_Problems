# Submission link: https://codeforces.com/gym/104487/submission/391104515
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        
        xs = []
        ys = []
        
        for _ in range(n):
            x, y = MII()
            xs.append(x)
            ys.append(y)
    
        ans = 2
        
        for i in range(n):
            for j in range(i):
                x1, y1 = xs[i], ys[i]
                x2, y2 = xs[j], ys[j]
                
                sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
                
                cnt = Counter()
                
                for k in range(j):
                    x3, y3 = xs[k], ys[k]
                    
                    if (x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2):
                        continue
                    
                    dx1, dy1 = x1 - x3, y1 - y3
                    dx2, dy2 = x2 - x3, y2 - y3
                    
                    a = (dx1 * dx1 + dy1 * dy1) + (dx2 * dx2 + dy2 * dy2) - sq
                    b = (dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2)
                    
                    flg = (a < 0) ^ ((x1 - x2) * (y1 - y3) < (x1 - x3) * (y1 - y2))
                    
                    a = a * a
                    g = math.gcd(a, b)
                    a //= g
                    b //= g
                    
                    cnt[(a if flg else -a, b)] += 1
    
                if cnt: ans = fmax(ans, max(cnt.values()) + 2)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))