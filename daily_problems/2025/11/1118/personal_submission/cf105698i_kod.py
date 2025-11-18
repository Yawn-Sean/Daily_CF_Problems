n = ix()
l = il()
l.sort()
d = [[0] * n for i in range(n)]
a = [[0] * n for _ in range(n)]
for i in range(n):
    p = 0
    for j in range(i + 1, n):
        while p < i and l[i] + l[p] <= l[j]:
            p += 1
        if p:
            d[i][j] = a[p - 1][i]
        d[i][j] += 1
        d[i][j] %= mod
        if i:
            a[i][j] = a[i - 1][j]
        a[i][j] += d[i][j]
        a[i][j] %= mod
ans = n
for x in d:
    ans = (ans + sum(x)) % mod
print(ans)
