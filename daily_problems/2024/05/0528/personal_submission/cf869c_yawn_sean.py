# Submission link: https://codeforces.com/contest/869/submission/262943523
def main():
    mod = 998244353
    fac = Factorial(5001, mod)
    a, b, c = MII()

    def f(x, y):
        ans = 0
        for i in range(min(x, y) + 1):
            ans += fac.combi(x, i) * fac.combi(y, i) % mod * fac.fac(i) % mod
            ans %= mod
        return ans

    print(f(a, b) * f(b, c) % mod * f(a, c) % mod)