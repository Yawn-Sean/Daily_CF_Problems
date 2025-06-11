def main():
    n, p, q, mod = MII()

    M = 200000
    f = [1] * (M + 1)
    c = [0] * (M + 1)

    for i in range(1, M + 1):
        v = i
        c[i] = c[i - 1]
        while v % mod == 0:
            v //= mod
            c[i] += 1
        f[i] = v * f[i - 1] % mod

    g = [0] * (M + 1)
    g[M] = pow(f[M], mod - 2, mod)

    for i in range(M, 0, -1):
        v = i
        while v % mod == 0:
            v //= mod
        g[i - 1] = v * g[i] % mod

    def combi(x, y):
        if c[x] > c[y] + c[x - y]: return 0
        return f[x] * g[y] % mod * g[x - y] % mod

    v1 = []
    v2 = []

    for _ in range(n):
        x, y = MII()
        v1.append(x + y - 1)
        v2.append(x)

    block = 450
    msk = [v1[i] // block * 1000 + (1 if v1[i] // block % 2 else -1) * v2[i] // block for i in range(n)]
    st_range = sorted(range(n), key=lambda x: msk[x])

    x1 = p
    x2 = q - p

    pw1 = [1] * (M + 1)
    pw2 = [1] * (M + 1)

    for i in range(1, M + 1):
        pw1[i] = pw1[i - 1] * x1 % mod
        pw2[i] = pw2[i - 1] * x2 % mod

    va, vb = 1, 1
    cur = p

    ans = [-1] * n
    rev_q = pow(q, mod - 2, mod)

    for i in st_range:
        a = v1[i]
        b = v2[i]
        
        while va < a:
            cur = cur * q % mod
            cur += combi(va, vb - 1) * pw1[vb] % mod * pw2[va - vb + 1] % mod
            if cur >= mod:
                cur -= mod
            va += 1
        
        while vb > b:
            vb -= 1
            cur += pw1[vb] * pw2[va - vb] % mod * combi(va, vb) % mod
            if cur >= mod:
                cur -= mod
        
        while va > a:
            va -= 1
            cur -= combi(va, vb - 1) * pw1[vb] % mod * pw2[va - vb + 1] % mod
            if cur < 0:
                cur += mod
            cur = cur * rev_q % mod

        while vb < b:
            cur -= pw1[vb] * pw2[va - vb] % mod * combi(va, vb) % mod
            if cur < 0:
                cur += mod
            vb += 1

        ans[i] = cur * q % mod

    print('\n'.join(map(str, ans)))
