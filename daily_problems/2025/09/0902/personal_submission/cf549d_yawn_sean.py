# Submission link: https://codeforces.com/contest/549/submission/336500561
def main():
    n, m = MII()
    grid = [[1 if c == 'B' else -1 for c in I()] for _ in range(n)]
    
    ans = 0
    
    for i in range(n):
        for j in range(m):
            v = grid[i][j]
            if i + 1 < n: v -= grid[i + 1][j]
            if j + 1 < m: v -= grid[i][j + 1]
            if i + 1 < n and j + 1 < m: v += grid[i + 1][j + 1]
            
            if v: ans += 1
    
    print(ans)