# Submission link: https://codeforces.com/contest/275/submission/320573277
def main():
    n, m = MII()
    grid = [[1 if c == 'B' else 0 for c in I()] for _ in range(n)]

    for i in range(n):
        cur = 0
        blocks = 1
        
        for j in range(m):
            if grid[i][j] != cur:
                cur = grid[i][j]
                blocks += 1
        
        if blocks >= 4: exit(print('NO'))

    for j in range(m):
        cur = 0
        blocks = 1
        
        for i in range(n):
            if grid[i][j] != cur:
                cur = grid[i][j]
                blocks += 1
        
        if blocks >= 4: exit(print('NO'))

    for i1 in range(n):
        for j1 in range(m):
            for i2 in range(n):
                for j2 in range(m):
                    if grid[i1][j1] and grid[i2][j2] and not grid[i1][j2] and not grid[i2][j1]:
                        exit(print('NO'))

    print('YES')