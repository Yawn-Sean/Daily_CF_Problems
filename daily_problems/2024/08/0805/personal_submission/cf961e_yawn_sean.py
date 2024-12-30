# Submission link: https://codeforces.com/contest/961/submission/274459320
def main():
    n = II()
    nums = LII()

    fen = FenwickTree(n)
    tmp = [[] for _ in range(n)]

    for i in range(n):
        tmp[fmin(n, nums[i]) - 1].append(i)

    ans = 0
    for i in range(n - 1, -1, -1):
        for x in tmp[i]:
            fen.add(x, 1)
        if nums[i] - 1 >= i + 1:
            ans += fen.rsum(i + 1, fmin(n, nums[i]) - 1)

    print(ans)