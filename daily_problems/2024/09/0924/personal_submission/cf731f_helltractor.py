def CF731F():
    n = II()
    a = LII()
    mx = 2 * 10 ** 5
    pre = [0] * (mx + 2)
    for x in a:
        pre[x + 1] += 1
    for i in range(mx + 1):
        pre[i + 1] += pre[i]
    ans = [0] * (mx + 1)
    for i in range(1, mx + 1):
        for j in range(0, mx + 1, i):
            ans[i] += j * (pre[fmin(mx + 1, j + i)] - pre[j])
    print(max(ans[x] for x in a))
