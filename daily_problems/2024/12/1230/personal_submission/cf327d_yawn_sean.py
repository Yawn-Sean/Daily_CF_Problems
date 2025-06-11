# Submission link: https://codeforces.com/contest/327/submission/299018008
def main():
    n, m = MII()
    grid = [[1 if c == '.' else 0 for c in I()] for _ in range(n)]

    ops = []
    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                ops.append(f'B {i + 1} {j + 1}')

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                stk = [i * m + j]
                grid[i][j] = 0
                order = []
                
                while stk:
                    x, y = divmod(stk.pop(), m)
                    for dx, dy in dirs:
                        if 0 <= x + dx < n and 0 <= y + dy < m and grid[x + dx][y + dy]:
                            grid[x + dx][y + dy] = 0
                            order.append((x + dx, y + dy))
                            stk.append((x + dx) * m + y + dy)

                order.reverse()
                for x, y in order:
                    ops.append(f'D {x + 1} {y + 1}')
                    ops.append(f'R {x + 1} {y + 1}')

    print(len(ops))
    print('\n'.join(ops))