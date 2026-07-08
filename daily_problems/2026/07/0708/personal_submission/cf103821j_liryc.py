'''
https://codeforces.com/gym/103821/submission/381696077
'''
MOD = 1000000007
fac = Factorial(2004, MOD)

def solve(n: int, k: int, c: list[int]) -> int:
    ca = list(Counter(c).values())
    ans = 0
    for j in range(1, k + 1):
        fa = 1
        for cnt in ca:
            m = fac.combi(cnt + j - 1, j - 1)
            fa = (fa * m) % MOD
        t = fac.combi(k, j) * fa % MOD
        if (k - j) % 2 == 1:
            ans = (ans - t + MOD) % MOD
        else:
            ans = (ans + t) % MOD
    return ans
