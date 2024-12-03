# Submission link: https://codeforces.com/contest/229/submission/294510536
def main():
    n, m = MII()
    cnt = [0] * (n + 1)

    for _ in range(m):
        u, v = MII()
        cnt[u] += 1
        cnt[v] += 1

    angles = 0
    for i in range(1, n + 1):
        angles += cnt[i] * (n - 1 - cnt[i])

    print(math.comb(n, 3) - angles // 2)