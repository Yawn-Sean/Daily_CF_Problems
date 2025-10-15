# Submission link: https://codeforces.com/contest/200/submission/316164491
def main():
    n, m, q = MII()

    vis = [[0] * (m + 2) for _ in range(n + 2)]
    dsus = [UnionFind(m + 2) for _ in range(n + 2)]

    cnt = [0] * (n + 2)
    dsu = UnionFind(n + 2)

    ls = [list(range(m + 2)) for _ in range(n + 2)]
    rs = [list(range(m + 2)) for _ in range(n + 2)]

    l = list(range(n + 2))
    r = list(range(n + 2))

    outs = []

    def check(vx, vy):
        global cur, cx, cy
        d = abs(vx - x) + abs(vy - y)
        if 1 <= vy <= m and (d < cur or (d == cur and (vx < cx or (vx == cx and vy < cy)))):
            cur = d
            cx, cy = vx, vy

    def operate(x, y1, y2):
        pl = fmin(ls[x][dsus[x].find(y1)], ls[x][dsus[x].find(y2)])
        pr = fmax(rs[x][dsus[x].find(y1)], rs[x][dsus[x].find(y2)])
        dsus[x].merge(y1, y2)
        y = dsus[x].find(y1)
        ls[x][y] = pl
        rs[x][y] = pr

    def operate1(x1, x2):
        pl = fmin(l[dsu.find(x1)], l[dsu.find(x2)])
        pr = fmax(r[dsu.find(x1)], r[dsu.find(x2)])
        dsu.merge(x1, x2)
        x = dsu.find(x1)
        l[x] = pl
        r[x] = pr

    for _ in range(q):
        x, y = MII()
        cur = n + m + 2
        cx, cy = -1, -1
        
        vx = x
        while vx > 0 and abs(vx - x) <= cur:
            if not vis[vx][y]:
                check(vx, y)
                break
            
            p = dsus[vx].find(y)
            
            vy = ls[vx][p] - 1
            check(vx, vy)
            
            vy = rs[vx][p] + 1
            check(vx, vy)
            
            vx = l[dsu.find(vx - 1)]
        
        vx = x
        while vx <= n and abs(vx - x) <= cur:
            if not vis[vx][y]:
                check(vx, y)
                break
            
            p = dsus[vx].find(y)
            
            vy = ls[vx][p] - 1
            check(vx, vy)
            
            vy = rs[vx][p] + 1
            check(vx, vy)
            
            vx = r[dsu.find(vx + 1)]

        outs.append(f'{cx} {cy}')
        
        vis[cx][cy] = 1
        
        if vis[cx][cy - 1]: operate(cx, cy, cy - 1)
        if vis[cx][cy + 1]: operate(cx, cy, cy + 1)
        
        cnt[cx] += 1
        
        if cnt[cx] == m:
            if cnt[cx - 1] == m: operate1(cx, cx - 1)
            if cnt[cx + 1] == m: operate1(cx, cx + 1)

    print('\n'.join(outs))