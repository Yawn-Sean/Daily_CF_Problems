n = int(input())
mod = 10 ** 9 + 7
print((pow(27, n, mod) - pow(7, n, mod)) % mod)
