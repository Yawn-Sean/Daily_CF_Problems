# Submission link: https://codeforces.com/contest/616/submission/317242646
def main():
    n, m = MII()
    grid = [I() for _ in range(n)]

    uf = UnionFind(n * m)

    def f(x, y):
        return x * m + y

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.':
                if i and grid[i - 1][j] == '.':
                    uf.merge(f(i - 1, j), f(i, j))
                if j and grid[i][j - 1] == '.':
                    uf.merge(f(i, j - 1), f(i, j))

    ans = [['.' for _ in range(m)] for _ in range(n)]
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '*':
                cnt = Counter()
                for di, dj in dirs:
                    if 0 <= i + di < n and 0 <= j + dj < m and grid[i + di][j + dj] == '.':
                        cnt[uf.find(f(i + di, j + dj))] = uf.getSize(f(i + di, j + dj))
                ans[i][j] = str((sum(cnt.values()) + 1) % 10)

    print('\n'.join(''.join(x) for x in ans))