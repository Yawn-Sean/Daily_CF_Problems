# Submission link: https://codeforces.com/contest/306/submission/320841014
def main():
    n, w, b = MII()
    mod = 10 ** 9 + 9

    f = Factorial(10000, mod)

    ans = 0

    for bad in range(1, n - 1):
        ans += f.combi(b - 1, bad - 1) * f.combi(w - 1, n - bad - 1) % mod * (n - 1 - bad) % mod
        ans %= mod

    print(ans * f.fac(w) % mod * f.fac(b) % mod)