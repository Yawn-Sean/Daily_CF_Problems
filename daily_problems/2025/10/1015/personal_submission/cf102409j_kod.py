n, l = il()
a = il()
a += l,
m1, m2 = 0, 0
ans = l
for m in range(n):
    while a[m1] < a[m] - a[m1]:
        m1 += 1
    while a[m2] - a[m] < a[-1] - a[m2]:
        m2 += 1
    for dm1 in range(m1 - 1, m1 + 1):
        for dm2 in range(m2 - 1, m2 + 1):
            p1, p2, p3, p4 = a[dm1], a[m] - a[dm1], a[dm2] - a[m], a[-1] - a[dm2]
            ans = min(ans, max(p1,p2,p3,p4) - min(p1,p2,p3,p4))
print(ans)
