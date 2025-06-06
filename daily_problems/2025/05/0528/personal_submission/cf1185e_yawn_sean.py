# Submission link: https://codeforces.com/contest/1185/submission/321713900
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m = MII()
        grid = [[-1 if c == '.' else ord(c) - ord('a') for c in I()] for _ in range(n)]
        
        x_min = [n] * 26
        x_max = [-1] * 26
        
        y_min = [m] * 26
        y_max = [-1] * 26
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] >= 0:
                    c = grid[i][j]
                    
                    x_min[c] = fmin(x_min[c], i)
                    x_max[c] = fmax(x_max[c], i)
                    
                    y_min[c] = fmin(y_min[c], j)
                    y_max[c] = fmax(y_max[c], j)
        
        ops = []
        xl, xr, yl, yr = n, -1, m, -1
        
        flg = True
        
        for i in range(25, -1, -1):
            if x_min[i] <= x_max[i]:
                if x_min[i] == x_max[i] or y_min[i] == y_max[i]:
                    xl = x_min[i]
                    xr = x_max[i]
                    yl = y_min[i]
                    yr = y_max[i]
                else:
                    flg = False
                    break
            if xl != n:
                ops.append((xl, xr, yl, yr))
        
        if not flg:
            outs.append('NO')
        else:
            ops.reverse()
            
            k = len(ops)
            tmp_grid = [[-1] * m for _ in range(n)]
            
            for i in range(k):
                xl, xr, yl, yr = ops[i]
                for x in range(xl, xr + 1):
                    for y in range(yl, yr + 1):
                        tmp_grid[x][y] = i
            
            for i in range(n):
                for j in range(m):
                    if grid[i][j] != tmp_grid[i][j]:
                        flg = False
            
            if not flg:
                outs.append('NO')
            else:
                outs.append('YES')
                outs.append(str(k))
                
                for xl, xr, yl, yr in ops:
                    outs.append(f'{xl + 1} {yl + 1} {xr + 1} {yr + 1}')

    print('\n'.join(outs))