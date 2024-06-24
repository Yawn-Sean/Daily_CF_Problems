mod = 10 ** 9 + 7 # 998244353

A, B, n, x = map(int, input().split())
ans = x * pow(A, n, mod)
ans += B * n if A == 1 else B * (pow(A, n, mod) - 1) * pow(A - 1, -1, mod)
print(ans % mod)
