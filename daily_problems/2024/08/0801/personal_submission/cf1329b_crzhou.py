t = int(input())
for _ in range(t):
    d, MOD = map(int, input().split())
    ans = tmp = 1
    while tmp <= d:
        ans *= min(tmp, d - tmp + 1) + 1   # min作用：当 tmp 到达 d 最高位时，此时的 xi 不是 2**tmp, 而是去除最高位后 + 1
        ans %= MOD
        tmp <<= 1
    print((ans - 1) % MOD)
