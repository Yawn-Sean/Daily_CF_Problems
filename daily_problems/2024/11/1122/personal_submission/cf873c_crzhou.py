n, m, k = MII()
a = []

for _ in range(n):
    a.append(LII())

ans = mo = 0
for j in range(m):
    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + a[i][j]
    cnt = tmp = tmpcnt = 0
    for i in range(n):
        if a[i][j]:
            if pre[fmin(i + k, n)] - pre[i] > tmp:
                tmpcnt = cnt
                tmp = pre[fmin(i + k, n)] - pre[i]
            cnt += 1
    mo += tmpcnt
    ans += tmp
print(ans, mo)
