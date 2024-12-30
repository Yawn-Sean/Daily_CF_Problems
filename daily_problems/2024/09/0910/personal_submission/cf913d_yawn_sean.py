# Submission link: https://codeforces.com/contest/913/submission/280511781
def main():
    n, t = MII()
    vals = []
    ts = []

    for _ in range(n):
        a, p = MII()
        vals.append(a)
        ts.append(p)

    st_range = list(range(n))
    st_range.sort(key=lambda x: -vals[x])

    ans = 0
    hpq = []
    cur = 0
    for i in st_range:
        heappush(hpq, -ts[i])
        cur += ts[i]
        if cur > t:
            cur += heappop(hpq)
        ans = fmax(ans, fmin(vals[i], len(hpq)))

    print(ans)

    st_range.sort(key=lambda x: ts[x])
    to_choose = []
    for i in st_range:
        if vals[i] >= ans and len(to_choose) < ans:
            to_choose.append(i + 1)

    print(len(to_choose))
    print(' '.join(map(str, to_choose)))