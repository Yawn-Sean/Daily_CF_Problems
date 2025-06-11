# Submission link: https://codeforces.com/contest/268/submission/286457166
def main():
    n = II()
    ls = [0] * n
    ps = [0] * n

    for i in range(n):
        ls[i], ps[i] = MII()

    def cmp(a, b):
        va = ls[a] * ps[a] * (100 - ps[b])
        vb = ls[b] * ps[b] * (100 - ps[a])
        if va > vb: return -1
        if va < vb: return 1
        return 0

    st_range = sorted(range(n), key=cmp_to_key(cmp))

    ans = 0
    cur = 0

    for i in st_range:
        ans += (100 - ps[i]) * cur + ls[i] * 10000
        cur += ls[i] * ps[i]

    print(ans / 10000)