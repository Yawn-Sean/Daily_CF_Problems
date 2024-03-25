import sys
input = lambda: sys.stdin.readline().strip()

# 假设 n = 8， k = 3
# a8b0 - a7b1 + a6b2
# a5b3 - a4b4 + a3b5 = (a8b0 - a7b1 + a6b2) // a3 * b3
# a2b6 - a1b7 + a0b8 = (a5b3 - a4b4 + a3b5) // a3 * b3
# 设 x = a8b0 - a7b1 + a6b2 ,  y = b3 // a3
# 结果为 x + x * y + x * y ^ 2  = x * (1 + y + y ^ 2) = x * (1 - y^((n + 1) // k)) // (1 - y)

MOD = 10 ** 9 + 9
n, a, b, k = map(int, input().split())
sign = [1 if c == "+" else -1 for c in input()]

ans = 0
for i in range(k):
    ans += sign[i] * (pow(a, n - i, MOD) * pow(b, i, MOD) % MOD)
    ans %= MOD

cnt = (n + 1) // k
q = pow(a, -k, MOD) * pow(b, k, MOD) % MOD
ans = ans * cnt % MOD if q == 1 else ans * (pow(q, cnt, MOD) - 1) % MOD * pow(q - 1, -1, MOD) % MOD
print(ans)
