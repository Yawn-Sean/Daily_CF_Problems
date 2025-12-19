n, m = map(int, input().split())
g = [list(input()) for _ in range(n)]

for i in range(n):
    for j in range(m):
        if g[i][j] == '.':
            g[i][j] = 'L'
            for ni in range(i + 1, n):
                if g[ni][j] == '#': break
                g[ni][j] = '*'

            for nj in range(j + 1, m):
                if g[i][nj] == '#': break
                g[i][nj] = '*'

print('\n'.join(''.join('.' if c == '*' else c for c in row) for row in g))
