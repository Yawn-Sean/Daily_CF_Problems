# Submission link: https://codeforces.com/contest/356/submission/295675555
def main():
    n, m = MII()
    s1 = I()
    s2 = I()
    k1 = len(s1)
    k2 = len(s2)

    g = math.gcd(k1, k2)
    ans = 0

    for i in range(g):
        cnt = Counter()
        for j in range(i, k1, g):
            cnt[s1[j]] += 1
        for j in range(i, k2, g):
            ans += cnt[s2[j]]

    print(n * k1 - math.gcd(n, m) * ans)