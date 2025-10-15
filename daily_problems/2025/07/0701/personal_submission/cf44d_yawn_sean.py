# Submission link: https://codeforces.com/contest/44/submission/326723988
def main():
    n = II()
    xs = []
    ys = []
    zs = []

    for _ in range(n):
        x, y, z = MII()
        xs.append(x)
        ys.append(y)
        zs.append(z)

    ans = inf

    def dis(i, j):
        return math.hypot(xs[i] - xs[j], ys[i] - ys[j], zs[i] - zs[j])

    for i in range(1, n):
        for j in range(i + 1, n):
            ans = fmin(ans, dis(0, i) + dis(0, j) + dis(i, j))

    print(ans / 2)