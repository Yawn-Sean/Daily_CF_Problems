def main():
    n, m, k = MII()
    us = []
    vs = []
    ws = []
    ans = 10**9

    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        ans = min(ans, abs(w - k))

    union = UnionFind(n)
    cur = 0
    for i in sorted(range(m), key=lambda x: ws[x]):
        if union.merge(us[i], vs[i]):
            cur += max(0, ws[i] - k)

    print(cur if cur else ans)  # 如果所有都比 k 小 答案是ans
    return


t = II()
for _ in range(t):
    main()
