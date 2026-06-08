import sys

input = lambda: sys.stdin.readline().rstrip()


n, X, Y = map(int, input().split())
a = list(map(int, input().split()))

MOD = 10**9 + 7
P = X * pow(Y, -1, MOD) % MOD
Q = (1 - P) % MOD

ans = 0
for i in range(30):
    for j in range(i + 1):
        dp = [1, 0, 0, 0]
        for x in a:
            nw = [0] * 4
            q = ((x >> i & 1) << 1) | (x >> j & 1)
            for p, v in enumerate(dp):
                nw[p] += v * Q
                nw[p ^ q] += v * P
            for p, v in enumerate(nw):
                dp[p] = v % MOD
        add = dp[-1] * (1 << (i + j)) % MOD
        if j != i:
            add = add * 2 % MOD
        ans = (ans + add) % MOD
print(ans)


"""
这道题求的是 E(s^2), 就有点烦
但是既然是异或, 我们依然考虑拆位
s := b0 + b1 + b2 + ... + b29
s^2 := (b0+...+b29) * (b0+...+b29)
    = sum(bi*bj for i in range(30) for j in range(30))
因为加法是可以分开的, 所以只要进行双重 for 循环枚举即可
bi*bj 只在 bi 和 bj 都不为 0 时才对期望有贡献
所以计算有多少种方案, 使得 bi, bj 都非 0
这个在遍历 a 的时候进行 dp 即可
哎, 司马卡常题
"""
