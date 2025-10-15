def yyn():
    m,r = MII()
    p = [2 * r]
    if m == 1:
        return print(2 * r)
    if m >= 2:
        p.append(2 * r + sqrt(r ** 2 + r ** 2))
    if m >= 3:
        p.append(p[-1] + sqrt(r ** 2 + r ** 2))
    for i in range(3,m):
        p.append(p[-1] + 2 * r)
    # print(p)
    pre = [0]
    for x in p:
        pre.append(pre[-1] + x)

    ans = 0

    for i in range(1,m + 1):
        left = i
        right = m - i + 1
        ans += pre[left] + pre[right] - 2 * r

    print(ans / (m * m))
