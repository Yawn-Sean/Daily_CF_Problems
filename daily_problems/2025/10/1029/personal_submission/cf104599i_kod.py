n = ix()
a = il()
pa = [0] + il()
ans = 0
dp1 = [0] * n
dp2 = [0] * n
for i in range(n - 1, -1, -1):
    ans = max(ans, dp1[i] + dp2[i])
    ans = max(ans, a[i] + dp1[i])
    if i > 0:
        t = max(a[i], dp1[i]) + 1
        p = pa[i] - 1
        if t > dp1[p]:
            dp1[p], dp2[p] = t, dp1[p]
        elif t > dp2[p]:
            dp2[p] = t
print(ans)
