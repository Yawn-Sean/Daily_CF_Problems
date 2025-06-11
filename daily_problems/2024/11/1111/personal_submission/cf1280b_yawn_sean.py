# Submission link: https://codeforces.com/contest/1280/submission/290927311
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m = MII()
        grid = [[1 if c == 'A' else 0 for c in I()] for _ in range(n)]
        
        f0, f5 = True, True
        for i in range(n):
            for j in range(m):
                if grid[i][j]: f5 = False
                else: f0 = False
        
        if f0: outs.append('0')
        elif f5: outs.append('MORTAL')
        else:
            f1 = False
            for j in [0, m - 1]:
                f = True
                for i in range(n):
                    if not grid[i][j]:
                        f = False
                if f: f1 = True
            
            for i in [0, n - 1]:
                f = True
                for j in range(m):
                    if not grid[i][j]:
                        f = False
                if f: f1 = True
            
            if f1:
                outs.append('1')
            else:
                f2 = False
                
                if grid[0][0] or grid[n - 1][0] or grid[0][m - 1] or grid[n - 1][m - 1]:
                    f2 = True
                else:
                    for i in range(n):
                        f = True
                        for j in range(m):
                            if not grid[i][j]:
                                f = False
                        if f: f2 = True
                    
                    for j in range(m):
                        f = True
                        for i in range(n):
                            if not grid[i][j]:
                                f = False
                        if f: f2 = True
                
                if f2:
                    outs.append('2')
                else:
                    f4 = True
                    for i in range(n):
                        for j in range(m):
                            if grid[i][j] and (i == 0 or i == n - 1 or j == 0 or j == m - 1):
                                f4 = False
                    outs.append('4' if f4 else '3')

    print('\n'.join(outs))