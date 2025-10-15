# Submission link: https://codeforces.com/contest/86/submission/328407974
def main():
    n, m = MII()
    grid = [[-1 if c == '#' else -2 for c in I()] for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if grid[i][j] == -2:
                c = (i % 3) + (j % 3) * 3
                grid[i][j] = c
                if j + 1 < m and grid[i][j + 1] == -2:
                    grid[i][j + 1] = c
                elif i + 1 < n and grid[i + 1][j] == -2:
                    grid[i + 1][j] = c
                else:
                    if j and grid[i][j - 1] != -1: grid[i][j] = grid[i][j - 1]
                    elif i and grid[i - 1][j] != -1: grid[i][j] = grid[i - 1][j]
                    elif j + 1 < m and grid[i][j + 1] != -1: grid[i][j] = grid[i][j + 1]
                    else: exit(print(-1))

    print('\n'.join(''.join('#' if x == -1 else str(x) for x in y) for y in grid))