# Submission link: https://codeforces.com/contest/859/submission/328168945
def main():
    n = II()
    mod = 10 ** 9 + 7

    us = []
    vs = []

    for _ in range(n):
        u, v = GMI()
        us.append(u)
        vs.append(v)

    dsu = UnionFind(2 * n)

    for i in range(n):
        dsu.merge(us[i], vs[i])

    cnt = [0] * (2 * n)
    flg = [1] * (2 * n)

    for i in range(n):
        cnt[dsu.find(us[i])] += 1
        if us[i] == vs[i]:
            flg[dsu.find(us[i])] = 0

    ans = 1

    for i in range(2 * n):
        if dsu.find(i) == i and flg[i]:
            sz = dsu.getSize(i)
            if cnt[i] < sz: ans = ans * sz % mod
            else: ans = ans * 2 % mod

    print(ans)
