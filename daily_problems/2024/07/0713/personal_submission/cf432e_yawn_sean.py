# Submission Link: https://codeforces.com/contest/432/submission/270251366
def main():
    n, m = MII()

    grid = [['.'] * m for _ in range(n)]

    dirs = [-1, 0, 1, 0, -1]

    def check(i, j, c):
        for d in range(4):
            di = dirs[d]
            dj = dirs[d+1]
            if 0 <= i + di < n and 0 <= j + dj < m and grid[i+di][j+dj] == c:
                return False
        return True

    def check1(i, j, c):
        for d in range(3):
            di = dirs[d]
            dj = dirs[d+1]
            if 0 <= i + di < n and 0 <= j + dj < m and grid[i+di][j+dj] == c:
                return False
        return True

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.':
                for c in ascii_uppercase:
                    if check(i, j, c):
                        grid[i][j] = c
                        break
                    
                    if check1(i, j, c):
                        nj = j - 1
                        while nj >= 0 and grid[i][nj] == c: nj -= 1
                        nj += 1
                        sz = j - nj
                        
                        if i + sz >= n: continue
                        
                        flg = True
                        for dx in range(sz + 1):
                            if grid[i+dx][nj+sz] != '.' and grid[i+dx][nj+sz] != c:
                                flg = False
                            if grid[i+sz][nj+dx] != '.' and grid[i+sz][nj+dx] != c:
                                flg = False
                        
                        if flg:
                            for dx in range(sz + 1):
                                grid[i+dx][nj+sz] = grid[i+sz][nj+dx] = c
                            break

    print('\n'.join(''.join(x) for x in grid))