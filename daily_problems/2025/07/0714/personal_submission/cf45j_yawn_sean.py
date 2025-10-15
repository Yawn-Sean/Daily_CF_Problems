# Submission link: https://codeforces.com/contest/45/submission/328788510
def main():
    n, m = MII()

    if 2 < n + m < 5: print(-1)
    else:
        grid = [[0] * m for _ in range(n)]
        
        pt = 1
        for i in range(n):
            for j in range(m):
                if (i + j) % 2:
                    grid[i][j] = pt
                    pt += 1
        
        for i in range(n):
            for j in range(m):
                if (i + j) % 2 == 0:
                    grid[i][j] = pt
                    pt += 1
        
        print('\n'.join(' '.join(map(str, x)) for x in grid))