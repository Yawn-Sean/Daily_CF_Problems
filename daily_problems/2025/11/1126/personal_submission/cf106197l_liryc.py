'''
https://codeforces.com/gym/106197/submission/350701652
'''
# constructive
def solve(n: int) -> list[str]:
    g = [[0] * n for _ in range(n)]
    g[-1][0] = 1
    for j in range(1, n):
        g[-1][j] = 3
    for i in range(1, n - 1):
        for j in range(-i, 0):
            g[i][j] = 2
    return [''.join(str(x + 1) for x in a) for a in g]

