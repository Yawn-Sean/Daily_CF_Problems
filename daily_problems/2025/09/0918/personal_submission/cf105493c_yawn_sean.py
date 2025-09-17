# Submission link: https://codeforces.com/gym/105493/submission/339027375
def main():
    n = II()
    x, y = MII()
    
    if n == 1:
        print('YES')
        print(1, 0)
        print(0, 1)
        exit()
    
    xs = []
    ys = []
    
    for _ in range(n - 1):
        nx, ny = MII()
        xs.append(nx - x)
        ys.append(ny - y)
        x, y = nx, ny
    
    def cmp(i, j):
        xi, yi = xs[i], ys[i]
        xj, yj = xs[j], ys[j]
    
        v = xi * yj - yi * xj
        if v > 0: return 1
        if v < 0: return -1
        return 0
    
    st_range = sorted(range(n - 1), key=cmp_to_key(cmp))
    
    i1 = st_range[0]
    i2 = st_range[-1]
    
    x1, y1 = xs[i1], ys[i1]
    x2, y2 = xs[i2], ys[i2]
    
    if x1 * x2 + y1 * y2 >= 0:
        vx, vy = x1 + x2, y1 + y2
    else:
        vx1, vy1 = y1, -x1
        if vx1 * x2 + vy1 * y2 < 0: vx1, vy1 = -vx1, -vy1
        vx2, vy2 = y2, -x2
        if vx2 * x1 + vy2 * y1 < 0: vx2, vy2 = -vx2, -vy2
        vx, vy = vx1 + vx2, vy1 + vy2
    
    for i in range(n - 1):
        if vx * xs[i] + vy * ys[i] <= 0:
            exit(print('NO'))
    
    print('YES')
    print(vx, vy)
    print(-vy, vx)