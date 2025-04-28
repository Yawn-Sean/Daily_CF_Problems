# Submission link: https://codeforces.com/contest/386/submission/313861164
def main():
    n = II()
    tx, ty, tz = GMI()
    if tx > ty: tx, ty = ty, tx
    if ty > tz: ty, tz = tz, ty
    if tx > ty: tx, ty = ty, tx
    grid = [[ord(c) for c in I()] for _ in range(n)]

    def f(i, j, k):
        return (i * n + j) * n + k

    prev = [-2] * (n ** 3)
    trans = [-1] * (n ** 3)

    que = [f(0, 1, 2)]
    prev[que[0]] = -1

    for u in que:
        v, z = divmod(u, n)
        x, y = divmod(v, n)
        
        for nx in range(n):
            if nx == x or nx == y or nx == z: continue
            if grid[x][nx] == grid[y][z]:
                a, b, c = nx, y, z
                if a > b: a, b = b, a
                if b > c: b, c = c, b
                if a > b: a, b = b, a
                nu = f(a, b, c)
                if prev[nu] == -2:
                    prev[nu] = u
                    trans[nu] = nx * n + x
                    que.append(nu)
        
        for ny in range(n):
            if ny == x or ny == y or ny == z: continue
            if grid[y][ny] == grid[x][z]:
                a, b, c = x, ny, z
                if a > b: a, b = b, a
                if b > c: b, c = c, b
                if a > b: a, b = b, a
                nu = f(a, b, c)
                if prev[nu] == -2:
                    prev[nu] = u
                    trans[nu] = ny * n + y
                    que.append(nu)
        
        for nz in range(n):
            if nz == x or nz == y or nz == z: continue
            if grid[z][nz] == grid[x][y]:
                a, b, c = x, y, nz
                if a > b: a, b = b, a
                if b > c: b, c = c, b
                if a > b: a, b = b, a
                nu = f(a, b, c)
                if prev[nu] == -2:
                    prev[nu] = u
                    trans[nu] = nz * n + z
                    que.append(nu)

    cur = f(tx, ty, tz)

    if prev[cur] == -2:
        exit(print(-1))

    outs = []

    while cur != f(0, 1, 2):
        a, b = divmod(trans[cur], n)
        outs.append(f'{a + 1} {b + 1}')
        cur = prev[cur]

    print(len(outs))
    print('\n'.join(outs))