mod = 998244353


def main():
    n = II()
    a, b = 1, 1
    for _ in range(n - 1):
        a, b = b, a + b
        b %= mod
    return a * pow(pow(2, mod - 2, mod), n, mod) % mod


T = 1
for ii in range(T):
    print(main())
