n, k = MII()
tmp = min(2, (n - 1) % k)
print((n - 1) // k * 2 + tmp)
outs = []
l = 1
for i in range(k):
    outs.append((l, i + 2))
l = 2
while l + k <= n:
    outs.append((l, l + k))
    l += 1
for a, b in outs:
    print(a, b)
