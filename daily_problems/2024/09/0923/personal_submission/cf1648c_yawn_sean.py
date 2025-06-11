# Submission link: https://codeforces.com/contest/1648/submission/282543922
def main():
    n, m = MII()
    s = LII()
    t = LII()

    M = 2 * 10 ** 5
    cnt = [0] * (M + 1)
    fen = FenwickTree(2 * 10 ** 5 + 1)

    for x in s:
        cnt[x] += 1
        fen.add(x, 1)

    mod = 998244353
    fac = Factorial(n, mod)

    cur = fac.fac(n)
    for v in cnt:
        cur = cur * fac.fac_inv(v) % mod

    ans = 0

    for i in range(m):
        if i >= n:
            ans += 1
            if ans == mod: ans = 0
            break
        
        cur = cur * fac.inv(n - i) % mod
        ans += cur * fen.rsum(0, t[i] - 1) % mod
        if ans >= mod: ans -= mod
        
        if cnt[t[i]] == 0: break

        cur = cur * cnt[t[i]] % mod
        cnt[t[i]] -= 1
        fen.add(t[i], -1)

    print(ans)