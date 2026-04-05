# Submission link: https://codeforces.com/gym/106457/submission/369872911
def main(): 
    d = {'.': 0, 'S': 1, '#': 2}
    dir = {
        'N': (-1, 0),
        'S': (1, 0),
        'W': (0, -1),
        'E': (0, 1)
    }
    
    n, m = MII()
    grid = [[d[c] for c in I()] for _ in range(n)]
    s = [dir[c] for c in I()]
    
    uf = UnionFind(n * n + 1)
    
    def f(i, j): return i * n + j
    
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 1:
                uf.merge(f(i, j), n * n)
            
            elif grid[i][j] == 0:
                x, y = i, j
                
                for dx, dy in s:
                    nx = x + dx
                    ny = y + dy
                    if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] != 2:
                        x = nx
                        y = ny
                        if grid[nx][ny] == 1:
                            break
                
                uf.merge(f(i, j), f(x, y))
    
    ans = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if uf.find(f(i, j)) == uf.find(n * n):
                ans[i][j] = 1
    
    print('\n'.join(''.join(map(str, x)) for x in ans))