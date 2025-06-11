def main():
    n, m, k = MII()
    grid = [LII() for _ in range(n)]

    dsu = UnionFind(n * m)
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def f(msk):
        x, y = divmod(msk, m)
        return -grid[x][y]

    tmp = list(range(n * m))
    tmp.sort(key=f)

    for msk in tmp:
        x, y = divmod(msk, m)
        for dx, dy in dirs:
            if 0 <= x + dx < n and 0 <= y + dy < m and grid[x + dx][y + dy] >= grid[x][y]:
                dsu.merge(x * m + y, (x + dx) * m + y + dy)
        
        if k % grid[x][y] == 0 and dsu.getSize(x * m + y) >= k // grid[x][y]:
            print('YES')
            
            v = grid[x][y]
            cnt = k // grid[x][y]
            
            ans = [[0] * m for _ in range(n)]
            stk = [x * m + y]
            
            ans[x][y] = v
            cnt -= 1
            
            while stk:
                x, y = divmod(stk.pop(), m)
                for dx, dy in dirs:
                    if 0 <= x + dx < n and 0 <= y + dy < m and grid[x + dx][y + dy] >= v and ans[x + dx][y + dy] == 0 and cnt > 0:
                        ans[x + dx][y + dy] = v
                        cnt -= 1
                        stk.append((x + dx) * m + y + dy)
            
            print('\n'.join(' '.join(map(str, x)) for x in ans))
            exit()

    print('NO')