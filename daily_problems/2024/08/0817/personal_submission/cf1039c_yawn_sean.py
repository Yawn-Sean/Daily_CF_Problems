# Submission link: https://codeforces.com/contest/1039/submission/276855859
def main():
    n, m, k = MII()
    nums = LII()

    us = []
    vs = []

    rnd = random.getrandbits(20)

    d = defaultdict(list)
    for i in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        d[nums[u] ^ nums[v] ^ rnd].append(i)

    mod = 10 ** 9 + 7
    pow2 = [1] * (5 * 10 ** 5 + 1)
    for i in range(5 * 10 ** 5):
        pow2[i+1] = 2 * pow2[i] % mod

    ans = (pow2[k] - len(d)) * pow2[n] % mod

    union = UnionFind(n)
    for x in d:
        cur = n
        for i in d[x]:
            cur -= union.merge(us[i], vs[i])
        ans += pow2[cur]
        ans %= mod
        for i in d[x]:
            union.reset(us[i])
            union.reset(vs[i])

    print(ans)