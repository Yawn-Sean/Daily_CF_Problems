# Submission link: https://codeforces.com/contest/2045/submission/329196315
def main():
    n, m, x = MII()
    grid = [[int(x) for x in I()] for _ in range(n)]
    
    d = {v: pow(v, x) for v in range(-9, 10)}
    
    dist = [[0] * m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            if i: dist[i][j] = dist[i - 1][j] + d[grid[i - 1][j] - grid[i][j]]
            if j: dist[i][j] = dist[i][j - 1] + d[grid[i][j - 1] - grid[i][j]]
    
    flg = True
    for i in range(n):
        for j in range(m):
            if i and dist[i][j] != dist[i - 1][j] + d[grid[i - 1][j] - grid[i][j]]:
                flg = False
            if j and dist[i][j] != dist[i][j - 1] + d[grid[i][j - 1] - grid[i][j]]:
                flg = False
    
    q = II()
    outs = []
    
    for _ in range(q):
        x1, y1, x2, y2 = GMI()
        if flg: outs.append(str(dist[x2][y2] - dist[x1][y1]))
        else: outs.append('INVALID')
    
    print('\n'.join(outs))