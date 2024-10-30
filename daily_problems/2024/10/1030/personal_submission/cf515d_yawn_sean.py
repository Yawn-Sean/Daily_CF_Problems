# Submission link: https://codeforces.com/contest/515/submission/288822079
def main():
    n, m = MII()
    grid = []

    for _ in range(n):
        grid.extend(list(I()))

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    chars = 'v<^>'

    def f(x, y):
        return x * m + y

    cnt = [0] * (n * m)

    stk = []
    for i in range(n):
        for j in range(m):
            if grid[f(i, j)] == '.':
                for dx, dy in dirs:
                    if 0 <= i + dx < n and 0 <= j + dy < m and grid[f(i + dx, j + dy)] == '.':
                        cnt[f(i, j)] += 1
                if cnt[f(i, j)] == 1:
                    stk.append(f(i, j))

    while stk:
        x, y = divmod(stk.pop(), m)
        
        if grid[f(x, y)] != '.': continue
        
        for i in range(4):
            dx, dy = dirs[i]
            if 0 <= x + dx < n and 0 <= y + dy < m and grid[f(x + dx, y + dy)] == '.':
                grid[f(x, y)] = chars[i]
                grid[f(x + dx, y + dy)] = chars[i ^ 2]
                cnt[f(x, y)] = 0
                cnt[f(x + dx, y + dy)] = 0
                
                nx, ny = x + dx, y + dy
                for ndx, ndy in dirs:
                    if 0 <= nx + ndx < n and 0 <= ny + ndy < m and grid[f(nx + ndx, ny + ndy)] == '.':
                        cnt[f(nx + ndx, ny + ndy)] -= 1
                        if cnt[f(nx + ndx, ny + ndy)] == 1:
                            stk.append(f(nx + ndx, ny + ndy))
                        
                break

    for i in range(n):
        for j in range(m):
            if grid[f(i, j)] == '.':
                exit(print('Not unique'))

    print('\n'.join(''.join(grid[f(i, j)] for j in range(m)) for i in range(n)))