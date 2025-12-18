# Submission link: https://codeforces.com/gym/105292/submission/353918809
def main(): 
    n, m = MII()
    grid = [[0 if c == '.' else 1 for c in I()] for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                grid[i][j] = 2
                
                for ni in range(i + 1, n):
                    if grid[ni][j] == 1: break
                    grid[ni][j] = 3
                
                for nj in range(j + 1, m):
                    if grid[i][nj] == 1: break
                    grid[i][nj] = 3
    
    print('\n'.join(''.join(" #L."[x] for x in y) for y in grid))