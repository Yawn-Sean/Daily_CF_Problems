# Submission link: https://codeforces.com/contest/538/submission/274090625
def main():
    n = II()
    nums = LII()

    fen = FenwickTree(n)
    ans = [0] * n

    for i in sorted(range(n), key=lambda x: nums[x]):
        for k in range(1, n):
            l, r = k * i + 1, k * (i + 1)
            if l >= n: break
            r = fmin(r, n - 1)
            ans[k] += fen.rsum(l, r)
        fen.add(i, 1)

    print(*ans[1:])