# Submission link: https://codeforces.com/contest/319/submission/293924332
def main():
    v = [int(x) for x in I()]
    n = len(v)

    mod = 10 ** 9 + 7
    ans = 0

    cur = 1
    for i in range(n - 1, -1, -1):
        ans += ans
        if ans >= mod: ans -= mod
        if v[i]:
            ans += cur * cur % mod
            if ans >= mod: ans -= mod
        cur += cur
        if cur >= mod: cur -= mod

    print(ans)