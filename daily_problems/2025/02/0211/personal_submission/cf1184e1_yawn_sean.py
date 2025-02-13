# Submission link: https://codeforces.com/contest/1184/submission/305534470
def main():
    n, m = MII()

    us = array('i')
    vs = array('i')
    ws = array('i')

    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        
        us.append(u)
        vs.append(v)
        ws.append(w)

    dsu = UnionFind(n)
    dsu1 = UnionFind(n)

    dsu.merge(us[0], vs[0])

    st_range = sorted(range(1, m), key=lambda x: ws[x])

    for i in st_range:
        if dsu.find(us[i]) != dsu.find(vs[i]):
            dsu.merge(us[i], vs[i])
            dsu1.merge(us[i], vs[i])

    ans = 10 ** 9

    for i in range(1, m):
        if dsu1.find(us[i]) != dsu1.find(vs[i]):
            ans = fmin(ans, ws[i])

    print(ans)