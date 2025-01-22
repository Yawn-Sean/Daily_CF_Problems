# Submission link: https://codeforces.com/contest/1043/submission/288403334
def main():
    n, m = MII()
    xs = [0] * n
    ys = [0] * n

    for i in range(n):
        xs[i], ys[i] = MII()

    ans = [0] * n

    st_range = sorted(range(n), key=lambda x: xs[x] - ys[x])
    totx = 0
    toty = sum(ys)

    for i in range(n):
        p = st_range[i]
        toty -= ys[p]
        ans[p] = totx + i * ys[p] + toty + (n - i - 1) * xs[p]
        totx += xs[p]

    for _ in range(m):
        u, v = GMI()
        val = fmin(xs[u] + ys[v], xs[v] + ys[u])
        ans[u] -= val
        ans[v] -= val

    print(' '.join(map(str, ans)))