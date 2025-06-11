# Submission link: https://codeforces.com/contest/729/submission/305876928
def main():
    n, k, s, t = MII()

    cs = []
    vs = []

    for _ in range(n):
        c, v = MII()
        cs.append(c)
        vs.append(v)

    st_range = sorted(range(n), key=lambda x: vs[x])

    stations = [0] + LII() + [s]
    stations.sort()

    inf = 2 * 10 ** 9 + 10

    l, r = 0, n - 1
    while l <= r:
        m = (l + r) // 2
        
        v = vs[st_range[m]]
        
        total = 0
        for i in range(k + 1):
            dis = stations[i + 1] - stations[i]
            if dis > v:
                total = inf
                break
            else:
                total += 2 * dis - fmin(dis, v - dis)
        
        if total <= t: r = m - 1
        else: l = m + 1

    print(min(cs[st_range[i]] for i in range(l, n)) if l < n else -1)