# Submission link: https://codeforces.com/contest/216/submission/321713236
def main():
    n = II()
    ars = []

    for _ in range(n):
        k, *vals = MII()
        vals.sort()
        ars.append(vals)

    ans = 0

    for i in range(n):
        for j in range(1, len(ars[i])):
            v1 = bisect.bisect_left(ars[i - 1], ars[i][j]) - bisect.bisect_left(ars[i - 1], ars[i][j - 1])
            v2 = bisect.bisect_left(ars[(i + 1) % n], ars[i][j]) - bisect.bisect_left(ars[(i + 1) % n], ars[i][j - 1])
            if v1 != v2: ans += 1

    print(ans)