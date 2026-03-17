t = int(input())
mod = 998244353

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    total = 0
    diff = 0
    for i in range(n):
        diff += a[i] * i - total
        total += a[i]
    diff = diff % mod
    ans = (diff * 2) % mod
    inv_n = pow(n, mod - 2, mod)
    ans = (ans * inv_n) % mod
    print(ans)
