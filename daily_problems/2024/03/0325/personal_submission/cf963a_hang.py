def main():
    n,a,b,k = map(int, input().split())
    s = input()
    mod = 10**9 + 9
    ans = 0
    c,d = divmod(n + 1, k)
    # 公比 （b/a)^k 注意要特别处理 p == 1时
    p = b * pow(a, -1, mod) % mod
    p = pow(p, k, mod)
    for i in range(k):
        # 首项
        start = (pow(a, n-i,mod) * pow(b, i, mod)) % mod
        z = c
        if i + 1 <= d:
            z += 1
        r = (start * z % mod) if p == 1 else ((start * (pow(p, z, mod) - 1)) % mod) * pow(p-1, -1, mod) % mod
        if s[i] == '+':
            ans = ans + r
        else:
            ans = ans - r
        ans %= mod
    print(ans)

main()