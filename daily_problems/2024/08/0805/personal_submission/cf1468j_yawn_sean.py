# Submission link: https://codeforces.com/contest/1468/submission/274458369
def main():
    n, m, k = MII()
    
    us = []
    vs = []
    ws = []
    ans = 10 ** 9
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        ans = fmin(ans, abs(w - k))
    
    union = UnionFind(n)
    cur = 0
    for i in sorted(range(m), key=lambda x: ws[x]):
        if union.merge(us[i], vs[i]):
            cur += fmax(0, ws[i] - k)
    
    outs.append(cur if cur else ans)