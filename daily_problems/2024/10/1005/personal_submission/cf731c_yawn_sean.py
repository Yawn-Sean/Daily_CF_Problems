# Submission link: https://codeforces.com/contest/731/submission/284379286
def main():
    n, m, k = MII()
    colors = LGMI()

    union = UnionFind(n)

    for _ in range(m):
        u, v = GMI()
        union.merge(u, v)

    cnts = [Counter() for _ in range(n)]
    for i in range(n):
        cnts[union.find(i)][colors[i]] += 1

    ans = n
    for x in cnts:
        if x:
            ans -= max(x.values())

    print(ans)