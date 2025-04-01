# Submission link: https://codeforces.com/contest/336/submission/313300325
def main():
    m, r = MII()
    r2 = r * 2 ** 0.5

    v0 = m * (2 * r)
    v1 = 2 * (m - 1) * (2 * r + r2)
    v2 = (m - 1) * (m - 2) * (2 * r2) + m * (m - 1) * (m - 2) // 3 * (2 * r)

    print((v0 + v1 + v2) / m / m)