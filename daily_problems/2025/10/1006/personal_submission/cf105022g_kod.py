n, k = il()
a = il()
b = il()
t1 = sum(a) % mod
t2 = sum(b) % mod
d = sum(a[i] * b[i] % mod for i in range(n)) % mod
print(t1 * t2 * pow(d, k - 1, mod) % mod)
