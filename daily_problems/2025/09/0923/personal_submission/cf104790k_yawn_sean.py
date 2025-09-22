# Submission link: https://codeforces.com/gym/104790/submission/339861279
def main():
    n = II()
    cur_max = 0
    saved = {}
    
    def query(x, y):
        if x == 0 or x == n + 1: return 0
        if y == 0 or y == n + 1: return 0
        
        nonlocal cur_max
        
        if (x, y) in saved:
            return saved[(x, y)]
        
        print('?', x, y, flush=True)
        res = II()
        cur_max = fmax(cur_max, res)
        saved[(x, y)] = res
        
        return res
    
    def solve(xl, xr, yl, yr):
        xm = (xl + xr) // 2
        ym = (yl + yr) // 2
        
        val = 0
        vx, vy = -1, -1
        
        for x in range(xl, xr + 1):
            nval = query(x, ym)
            if nval > val:
                val = nval
                vx, vy = x, ym
            
            nval = query(x, yl - 1)
            if nval > val:
                val = nval
                vx, vy = x, yl - 1
            
            nval = query(x, yr + 1)
            if nval > val:
                val = nval
                vx, vy = x, yr + 1
        
        for y in range(yl, yr + 1):
            nval = query(xm, y)
            if nval > val:
                val = nval
                vx, vy = xm, y
            
            nval = query(xl - 1, y)
            if nval > val:
                val = nval
                vx, vy = xl - 1, y
            
            nval = query(xr + 1, y)
            if nval > val:
                val = nval
                vx, vy = xr + 1, y
        
        for dx, dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx, ny = vx + dx, vy + dy
            if xl <= nx <= xr and yl <= ny <= yr and query(nx, ny) > val:
                if nx > xm:
                    if ny > ym: solve(xm + 1, xr, ym + 1, yr)
                    else: solve(xm + 1, xr, yl, ym - 1)
                else:
                    if ny > ym: solve(xl, xm - 1, ym + 1, yr)
                    else: solve(xl, xm - 1, yl, ym - 1)
    
    solve(1, n, 1, n)
    print('!', cur_max)