# Submission link: https://codeforces.com/gym/104887/submission/386299459
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        r, c, m, k = MII()
        
        if k > fmin(r, c): outs.append('NO')
        elif m < k or m > fmax(r, c) * k: outs.append('NO')
        else:
            grid = [[0] * c for _ in range(r)]
            
            for i in range(k):
                grid[i][i] = 1
                m -= 1
    
            for i in range(k if r < c else r):
                for j in range(k if c < r else c):
                    if m and grid[i][j] == 0:
                        grid[i][j] = 1
                        m -= 1
            
            outs.append('YES')
            outs.append('\n'.join(''.join('.#'[v] for v in x) for x in grid))
    
    print('\n'.join(outs))