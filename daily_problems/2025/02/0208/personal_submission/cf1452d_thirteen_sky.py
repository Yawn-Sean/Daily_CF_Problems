n = int(input())
f1 = 0
f2 = 1
mod = 998244353
for i in range(1, n):
    tmp = f1 + f2
    f1 = f2
    f2 = tmp
    f1 %= mod
    f2 %= mod
print(f2 * pow(pow(2, n, mod), mod - 2, mod) % mod)
