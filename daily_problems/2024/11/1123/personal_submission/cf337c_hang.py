def main():
    n,m,k = map(int,input().split())
    mod = 10**9+9
    a = min(m, n - n // k)
    b = m - a
    a -= (k - 1) * b
    print((k * (pow(2, b + 1, mod) - 2) + a) % mod)

main()