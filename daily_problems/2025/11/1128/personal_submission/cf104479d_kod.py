n, a, b = il()
p = a * pow(b, -1, mod) % mod
ans = c = 1
v = p
for i in range(2, n + 1):
    ans = ans * c % mod
    v = v * p % mod
    c = (c * (1 - p) + v) % mod
print(ans)
