def main():
    x,k = map(int, input().split())
    mod = 10**9+7
    print((pow(2, k, mod) * (2 * x - 1) % mod + 1) % mod if x else 0)

main()