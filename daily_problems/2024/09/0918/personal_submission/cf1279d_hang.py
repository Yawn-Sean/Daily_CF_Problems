
from collections import Counter
def main():
    n = int(input())
    mod = 998244353
    g = [0] * (10 ** 6 + 1) # 1 / (i!)
    f = [1] * (10 ** 6 + 1) # (i!)
    for i in range(1, 10 ** 6 + 1):
        f[i] = f[i - 1] * i % mod
    g[10**6] = pow(f[10**6], mod - 2, mod)
    for i in range(10 **6, 0, -1):
        g[i-1] = g[i] * i % mod

    # return 1 / x
    def inv(x):
        return f[x - 1] * g[x] % mod
    cnt = Counter()
    p = []
    for _ in range(n):  
        a = list(map(int, input().split()))[1:]
        p.append(a)
        for i in a:
            cnt[i] += 1
    ans = 0
    for i in range(n):
        for v in p[i]:
            ans = (ans + cnt[v] * inv(len(p[i]))) % mod
    ans = (ans * inv(n) % mod) * inv(n) % mod
    print(ans)
main()