n = ix()
p = [tuple(il()) for i in range(n)]
v = set(p)
ans = 0
for i in range(n):
    for j in range(i):
        a, b = p[i]
        c, d = p[j]
        e, f = c - a, d - b
        if (c - f, d + e) in v and (a - f, b + e) in v:
            ans += 1
        if (a + f, b - e) in v and (c + f, d - e) in v:
            ans += 1
print(ans // 4)
