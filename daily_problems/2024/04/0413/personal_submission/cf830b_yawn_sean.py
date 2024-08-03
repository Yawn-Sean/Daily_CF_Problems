# Submission link: https://codeforces.com/contest/830/submission/256410686
def main():
    n = II()
    nums = LII()

    idxs = [[] for _ in range(10 ** 5 + 1)]
    for i in range(n):
        idxs[nums[i]].append(i)

    fen = FenwickTree(1 for _ in range(n))

    ans = 0
    pt = 0
    for v in range(10 ** 5 + 1):
        p = bisect.bisect_left(idxs[v], pt)
        m = len(idxs[v])
        for idx in range(m):
            i = idxs[v][(p + idx) % m]
            if i >= pt:
                ans += fen.rsum(pt, i)
            else:
                ans += fen.rsum(pt, n - 1) + fen.sum(i)
            fen.add(i, -1)
            pt = i

    print(ans)