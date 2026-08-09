# Submission link: https://codeforces.com/gym/104882/submission/386298311
def main():
    n, m, k = MII()
    
    if n == 1:
        print('YES')
        print(''.join(str(fmin(i, k - 1) % 2) for i in range(m)))
    elif m == 1:
        print('YES')
        print('\n'.join(str(fmin(i, k - 1) % 2) for i in range(n)))
    elif k == n * m - 1:
        print('NO')
    else:
        grid = [[-1] * m for _ in range(n)]
        
        if k <= m:
            for i in range(n):
                for j in range(m):
                    grid[i][j] = fmin(j, k - 1) % 2
        else:
            first = (k - 1) // m + 1
            for i in range(first):
                for j in range(m):
                    if i * m + j <= k:
                        grid[i][j] = (i + j) % 2
                    else:
                        grid[i][j] = 1 - (i + j) % 2
            
            for i in range(first, n):
                for j in range(m):
                    grid[i][j] = grid[i - 1][j]
            
            if k % m == m - 1:
                grid[first - 1][m - 1] = grid[first - 2][m - 1]
        
        print('YES')
        print('\n'.join(''.join(map(str, x)) for x in grid))