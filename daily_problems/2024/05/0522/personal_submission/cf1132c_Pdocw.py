def main():
    n, q = MII()

    cur = [0] * n

    ls = []
    rs = []
    for _ in range(q):
        l, r = GMI()
        ls.append(l)
        rs.append(r)

        for i in range(l, r + 1):
            cur[i] += 1

    acc = [0] * (n + 1)  # acc[i]表示前i个区间的交集长度
    # 求删除两个区间交集最大的区间
    ans = 0

    for i in range(q):
        l, r = ls[i], rs[i]
        for j in range(l, r + 1):
            cur[j] -= 1

        cnt = 0
        for j in range(n):
            acc[j + 1] = acc[j]  # 前缀和
            if cur[j] >= 1:
                cnt += 1
            if cur[j] == 1:
                acc[j + 1] += 1
        for j in range(i):
            ans = max(ans, cnt - (acc[rs[j] + 1] - acc[ls[j]]))

        # 补回当前区间
        for j in range(l, r + 1):
            cur[j] += 1

    print(ans)
    return


t = 1
for _ in range(t):
    main()
