# Submission link: https://codeforces.com/contest/336/submission/280920104
def main():
    n, m, g = MII()

    mod = 10 ** 9 + 7
    fact = Factorial(n + m, mod)

    if m == 0:
        cur = 0
        for i in range(n - 1):
            cur = 1 - (cur | 0)
        if cur == g: print(1)
        else: print(0)

    elif m == 1:
        ans = 0
        cur = 0
        for i in range(n):
            if cur == g: ans += 1
            cur = 1 - (cur | 0)
        print(ans + (cur != g))

    else:
        ans = 0
        cur = 0
        for c0 in range(n + 1):
            if cur == g:
                ans += fact.combi(n + m - 1 - c0, n - c0)
                if ans >= mod:
                    ans -= mod
            cur = 1 - (cur | 0)
        print(ans)