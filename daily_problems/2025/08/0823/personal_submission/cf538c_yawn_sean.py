# Submission link: https://codeforces.com/contest/538/submission/335041709
def main():
    n, m = MII()

    ds = []
    hs = []

    for _ in range(m):
        d, h = MII()
        ds.append(d)
        hs.append(h)

    ans = fmax(ds[0] - 1 + hs[0], n - ds[-1] + hs[-1])

    for i in range(1, m):
        diff_d = ds[i] - ds[i - 1]
        if abs(hs[i] - hs[i - 1]) > diff_d:
            exit(print('IMPOSSIBLE'))
        ans = fmax(ans, (hs[i] + hs[i - 1] + diff_d) // 2)

    print(ans)