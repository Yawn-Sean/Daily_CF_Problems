mod = 998244353
n = int(input())
a = [int(x) for x in input().split()]
a = sorted(a)
m = sum(a)
f = [1] + [0] * (m + 2)
ans = 0

for x in a :
    for i in range(x) :
        ns = x + i
        ns = ns + (ns & 1)
        ns = ns // 2

        ans -= ns * f[i] % mod
        ans += x * f[i] % mod
        ans += mod
        ans %= mod

    for i in range(m, x - 1, -1) :
        f[i] += f[i - x]
        f[i] %= mod

for i in range(1, m + 1) :
    x = i + (i & 1)
    ans += x // 2 * f[i] % mod
    ans %= mod

print(ans)
