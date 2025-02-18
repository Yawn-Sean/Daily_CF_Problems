n, q = MII()
a = LII()
b = LII()
prea = [0] * n
preb = [0] * n
for i in range(n - 1):
    prea[i + 1] = prea[i] + ((a[i + 1] ^ a[i]) & 1)
    preb[i + 1] = preb[i] + ((b[i + 1] ^ b[i]) & 1)
for _ in range(q):
    l, r, x, y = MII()
    if prea[l - 1] == prea[x - 1] and preb[r - 1] == preb[y - 1]:
        print("YES")
    else:
        print("NO")
