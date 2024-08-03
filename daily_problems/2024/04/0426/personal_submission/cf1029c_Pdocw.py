def main():
    n = II()
    ls = []
    rs = []

    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)
    pre_max_l = [0] * n
    pre_min_r = [inf] * n

    for i in range(n - 1):
        pre_max_l[i + 1] = max(pre_max_l[i], ls[i])
        pre_min_r[i + 1] = min(pre_min_r[i], rs[i])

    suf_max_l = 0
    suf_min_r = inf
    ans = 0
    for i in range(n - 1, -1, -1):
        # print(pre_max_l[i], pre_min_r[i], suf_max_l, suf_min_r, ans)
        ans = max(
            ans, max(0, min(suf_min_r, pre_min_r[i]) - max(suf_max_l, pre_max_l[i]))
        )
        suf_max_l = max(suf_max_l, ls[i])
        suf_min_r = min(suf_min_r, rs[i])
    print(ans)
    return
