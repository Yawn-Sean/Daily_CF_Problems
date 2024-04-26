# Submission link: https://codeforces.com/contest/1029/submission/258172587
def main():
    n = II()

    ls = []
    rs = []
    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)


    pref_ma_l = [-inf] * n
    pref_mi_r = [inf] * n

    for i in range(n - 1):
        pref_ma_l[i+1] = max(pref_ma_l[i], ls[i])
        pref_mi_r[i+1] = min(pref_mi_r[i], rs[i])

    suff_ma_l = -inf
    suff_mi_r = inf

    ans = 0

    for i in range(n - 1, -1, -1):
        ans = max(ans, min(suff_mi_r, pref_mi_r[i]) - max(suff_ma_l, pref_ma_l[i]))
        suff_ma_l = max(suff_ma_l, ls[i])
        suff_mi_r = min(suff_mi_r, rs[i])

    print(ans)