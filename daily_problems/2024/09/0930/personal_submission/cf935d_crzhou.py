# 逆元
MOD = 10**9 + 7

def frac(a, b):
    return a * pow(b, MOD - 2, MOD)

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = 0
lst = 1   # 相等的概率

for i in range(n):
    if a[i] and b[i] and a[i] != b[i]:
        print((ans + lst * (a[i] > b[i])) % MOD)
        exit()
    elif not a[i] and not b[i]:
        ans = (ans + lst * frac(m - 1, 2 * m) % MOD) % MOD   # 之前相等的概率 * (m-1) / 2m
        lst = lst * frac(1, m) % MOD
    elif not a[i] and b[i]:
        ans = (ans + lst * frac(m - b[i], m) % MOD) % MOD    # 之前相等的概率 * (m-b[i]) / m
        lst = lst * frac(1, m) % MOD
    elif a[i] and not b[i]:
        ans = (ans + lst * frac(a[i] - 1, m) % MOD) % MOD    # 之前相等的概率 * (a[i]-1) / m
        lst = lst * frac(1, m) % MOD

print(ans)
