# Submission Link: https://codeforces.com/contest/366/submission/267586697
def main():
    n, m = MII()

    us = []
    vs = []
    ls = []
    rs = []

    for _ in range(m):
        u, v, l, r = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ls.append(l)
        rs.append(r)

    union = UnionFind(n)

    tmp_l = sorted(set(ls))
    tmp_r = sorted(set(rs))

    def check(pl, pr):
        for i in range(m):
            if tmp_l[pl] >= ls[i] and tmp_r[pr] <= rs[i]:
                union.merge(us[i], vs[i])
        flg = union.find(0) == union.find(n - 1)
        union.init()
        return flg

    ans = 0
    pl, pr = 0, 0
    while pl < len(tmp_l):
        while pr < len(tmp_r) and check(pl, pr):
            pr += 1
        if pr and tmp_r[pr-1] - tmp_l[pl] + 1 > ans:
            ans = tmp_r[pr-1] - tmp_l[pl] + 1
        pl += 1

    print(ans if ans else 'Nice work, Dima!')