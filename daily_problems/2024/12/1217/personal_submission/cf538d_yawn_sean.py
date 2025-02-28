# Submission link: https://codeforces.com/contest/538/submission/296907653
def main():
    n = II()
    grid = [I() for _ in range(n)]

    ans = [['x'] * (2 * n - 1) for _ in range(2 * n - 1)]

    for i in range(n):
        for j in range(n):
            if grid[i][j] == 'o':
                for ni in range(n):
                    for nj in range(n):
                        if grid[ni][nj] == '.':
                            ans[ni - i + n - 1][nj - j + n - 1] = '.'
    ans[n - 1][n - 1] = 'o'

    for i in range(n):
        for j in range(n):
            if grid[i][j] == 'x':
                flg = False
                for di in range(2 * n - 1):
                    for dj in range(2 * n - 1):
                        if ans[di][dj] == 'x':
                            oi = i - (di - n + 1)
                            oj = j - (dj - n + 1)
                            if 0 <= oi < n and 0 <= oj < n and grid[oi][oj] == 'o':
                                flg = True
                if not flg:
                    exit(print('NO'))

    print('YES')
    print('\n'.join(''.join(x) for x in ans))