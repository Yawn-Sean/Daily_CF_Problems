# Submission link: https://codeforces.com/contest/870/submission/280134767
def main():
    n = II()
    xs = []
    ys = []
    rnd = random.getrandbits(20)

    for _ in range(n):
        x, y = MII()
        xs.append(x + rnd)
        ys.append(y + rnd)

    d_x = {v: i for i, v in enumerate(set(xs))}
    d_y = {v: i for i, v in enumerate(set(ys))}

    kx = len(d_x)
    ky = len(d_y)

    union = UnionFind(kx + ky)

    for i in range(n):
        union.merge(d_x[xs[i]], kx + d_y[ys[i]])

    edges_cnt = [0] * (kx + ky)
    for i in range(n):
        edges_cnt[union.find(d_x[xs[i]])] += 1

    ans = 1
    mod = 10 ** 9 + 7
    for i in range(kx + ky):
        if edges_cnt[i]:
            c = union.getSize(i)
            ans *= pow(2, c, mod) if edges_cnt[i] >= c else pow(2, c, mod) - 1
            ans %= mod

    print(ans)