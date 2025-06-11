# Submission link: https://codeforces.com/contest/374/submission/303165997
def main():
    d = {'D': 0, 'I': 1, 'M': 2, 'A': 3}
    n, m = MII()

    grid = [[d[c] for c in I()] for _ in range(n)]
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    path = [[] for _ in range(n * m)]

    def f(x, y):
        return x * m + y

    invs = [0] * (n * m)
    for i in range(n):
        for j in range(m):
            for di, dj in dirs:
                if 0 <= i + di < n and 0 <= j + dj < m and (grid[i + di][j + dj] - grid[i][j]) % 4 == 1:
                    path[f(i, j)].append(f(i + di, j + dj))
                    invs[f(i + di, j + dj)] += 1

    stk = [i for i in range(n * m) if invs[i] == 0] 
    ans = [-1] * (n * m)

    for i in stk:
        x, y = divmod(i, m)
        ans[i] = grid[x][y]
        if ans[i] == 0: ans[i] = 4

    while stk:
        u = stk.pop()
        for v in path[u]:
            invs[v] -= 1
            ans[v] = fmax(ans[v], ans[u] + 1)
            if invs[v] == 0:
                stk.append(v)

    if max(invs): exit(print('Poor Inna!'))

    res = (max(ans) - 3) // 4
    print(res if res > 0 else 'Poor Dima!')