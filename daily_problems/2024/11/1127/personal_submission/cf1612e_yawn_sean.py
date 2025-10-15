# Submission link: https://codeforces.com/contest/1612/submission/293424688
def main():
    n = II()
    ms = []
    ks = []

    for _ in range(n):
        m, k = MII()
        ms.append(m)
        ks.append(k)

    ans = []
    x, y = 0, 1

    for t in range(1, min(n, 20) + 1):
        cnt = Counter()
        for i in range(n):
            cnt[ms[i]] += min(t, ks[i])
        tot = sum(nlargest(t, cnt.values()))
        if tot * y > x * t:
            x, y = tot, t

    cnt = Counter()
    for i in range(n):
        cnt[ms[i]] += min(y, ks[i])
    ids = list(cnt.keys())
    ids.sort(lambda x: -cnt[x])

    print(y)
    print(' '.join(str(x) for x in ids[:y]))