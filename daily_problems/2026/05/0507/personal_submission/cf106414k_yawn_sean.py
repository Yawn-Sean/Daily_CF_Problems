# Submission link: https://codeforces.com/gym/106414/submission/373699965
def main():
    t = II()
    outs = []
    
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    for _ in range(t):
        n, m = MII()
        pts = []
    
        vis = 0
        
        for _ in range(3):
            x, y = GMI()
            pts.append((x, y))
            vis |= 1 << ((x + y) % 2)
    
        ans = [[0] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                ans[i][j] = (i + j) % 2
        
        if vis == 3:
            vis = 0
            
            for x, y in pts:
                if vis >> ((x + y) % 2) & 1:
                    ans[x][y] = 2
                vis |= 1 << ((x + y) % 2)
            
            outs.append('YES')
            
            for x in ans:
                outs.append(''.join('RGB'[i] for i in x))
        
        else:
            flg = False
            
            for i in range(3):
                for j in range(i):
                    x1, y1 = pts[i]
                    x2, y2 = pts[j]
                    
                    if abs(x1 - x2) + abs(y1 - y2) > 2:
                        ans[x1][y1] = 2
                        
                        ans[x2][y2] ^= 1
                        
                        for dx, dy in dirs:
                            if 0 <= x2 + dx < n and 0 <= y2 + dy < m:
                                ans[x2 + dx][y2 + dy] = 2
                        
                        flg = True
                    
                    if flg: break
                if flg: break
            
            if flg:
                outs.append('YES')
                
                for x in ans:
                    outs.append(''.join('RGB'[i] for i in x))
            
            else:
                outs.append('NO')
    
    print('\n'.join(outs))