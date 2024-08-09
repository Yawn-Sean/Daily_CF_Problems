# Submission link: https://codeforces.com/contest/575/submission/275317107
def main():
    n, x = MII()
    l, r = x, x
    ans = 0

    for _ in range(n):
        nl, nr = MII()
        if fmax(nl, l) <= fmin(nr, r):
            l = fmax(nl, l)
            r = fmin(nr, r)
        elif r < nl:
            ans += nl - r
            l, r = r, nl
        else:
            ans += l - nr
            l, r = nr, l

    print(ans)