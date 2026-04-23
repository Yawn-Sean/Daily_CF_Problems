# Submission link: https://codeforces.com/gym/106495/submission/372220000
def main():
    n = II()
    px, py = MII()
    
    xs = []
    ys = []
    rs = []
    
    for _ in range(n):
        x, y, r = MII()
        xs.append(x)
        ys.append(y)
        rs.append(r)
    
    ans = 1e14
    
    def check(x, y):
        global ans
        for i in range(n):
            x0, y0, r0 = xs[i], ys[i], rs[i]
            if (x - x0) * (x - x0) + (y - y0) * (y - y0) > r0 * r0 + 1e-6: return 
        ans = fmin(ans, (x - px) * (x - px) + (y - py) * (y - py))
    
    check(px, py)
    
    for i in range(n):
        for j in range(i):
            x1, y1, r1 = xs[i], ys[i], rs[i]
            x2, y2, r2 = xs[j], ys[j], rs[j]
            
            dx = x2 - x1
            dy = y2 - y1
            dis = dx * dx + dy * dy
            
            if dis < (r1 - r2) * (r1 - r2) or dis > (r1 + r2) * (r1 + r2) or dis == 0:
                continue
            
            tmp = r1 * r1 - r2 * r2 + dis
            
            midx = x1 + tmp * dx / dis / 2
            midy = y1 + tmp * dy / dis / 2
            
            tmpx = -math.sqrt(4 * r1 * r1 * dis - tmp * tmp) * dy / dis / 2
            tmpy = math.sqrt(4 * r1 * r1 * dis - tmp * tmp) * dx / dis / 2
            
            check(midx + tmpx, midy + tmpy)
            check(midx - tmpx, midy - tmpy)
    
    for i in range(n):
        x0, y0, r0 = xs[i], ys[i], rs[i]
        if (px - x0) * (px - x0) + (py - y0) * (py - y0) > r0 * r0:
            dx, dy = px - x0, py - y0
            ratio = r0 / math.hypot(dx, dy)
            check(x0 + ratio * dx, y0 + ratio * dy)
    
    print(math.sqrt(ans))