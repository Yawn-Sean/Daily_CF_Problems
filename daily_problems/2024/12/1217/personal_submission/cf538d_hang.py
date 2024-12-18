#题解： https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/12/1217/solution/cf538d.md
def main():
    n = int(input())
    g = [input() for _ in range(n)]
    ans = [['x'] * (2 * n - 1) for _ in range(2 * n - 1)]
    for i in range(n):
        for j in range(n):
            if g[i][j] == 'o':
                for ni in range(n):
                    for nj in range(n):
                        if g[ni][nj] == '.':
                            ans[ni - i + n - 1][nj - j + n - 1] = '.'
                
    ans[n - 1][n - 1] = 'o'
    for i in range(n):
        for j in range(n):
            if g[i][j] == 'x':
                k = False
                for di in range(2 * n - 1):
                    for dj in range(2 * n - 1):
                        if ans[di][dj] == 'x':
                            oi = i - (di - n + 1)
                            oj = j - (dj - n + 1)
                            if 0 <= oi < n and 0 <= oj < n and g[oi][oj] == 'o':
                                k = True
                if not k:
                    exit(print('NO'))

    print('YES')
    print('\n'.join(''.join(x) for x in ans))
main()