# Submission link: https://codeforces.com/gym/105442/submission/378594439
def main():
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    o1 = sorted(range(n), key=lambda x: (xs[x], ys[x]))
    o2 = sorted(range(n), key=lambda x: (ys[x], -xs[x]))
    o3 = sorted(range(n), key=lambda x: (-xs[x], -ys[x]))
    o4 = sorted(range(n), key=lambda x: (-ys[x], xs[x]))
    
    p1 = 0
    p2 = 0
    p3 = 0
    p4 = 0
    
    vis = [0] * n
    
    for _ in range(n // 4 - 1):
        while vis[o1[p1]]: p1 += 1
        vis[o1[p1]] = 1
        
        while vis[o2[p2]]: p2 += 1
        vis[o2[p2]] = 1
        
        while vis[o3[p3]]: p3 += 1
        vis[o3[p3]] = 1
        
        while vis[o4[p4]]: p4 += 1
        vis[o4[p4]] = 1
    
    pts = []
    
    for i in range(n):
        if not vis[i]:
            pts.append((xs[i], ys[i]))
    
    x1, y1 = pts[0]
    x2, y2 = pts[1]
    x3, y3 = pts[2]
    
    dx1, dy1 = x2 - x1, y2 - y1
    dx2, dy2 = x3 - x1, y3 - y1
    
    print(abs(dx1 * dy2 - dy1 * dx2))