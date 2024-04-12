# Submission link: https://codeforces.com/contest/540/submission/256182378
def main():
    n = II()
    rnd = random.getrandbits(20)
    
    d = {}
    for _ in range(n):
        x, y = MII()
        x += rnd
        y += rnd
        if x not in d: d[x] = x
        if y not in d: d[y] = y
        d[x], d[y] = d[y], d[x]

    pos = {d[v]: v for v in d}
    pts = sorted(d)
    map_pos = {v: i * 2 for i, v in enumerate(pts)}
    
    n = len(pts)
    fen = FenwickTree(2 * n - 1)
    
    ans = 0
    for i in range(n - 1, -1, -1):
        if i < n - 1:
            p = 2 * i + 1
            ans += fen.sum(p) * (pts[i + 1] - pts[i] - 1)
            fen.add(p, pts[i + 1] - pts[i] - 1)
        
        p = map_pos[pos[pts[i]]]
        ans += fen.sum(p)
        fen.add(p, 1)
    
    print(ans)