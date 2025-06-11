# Submission Link: https://codeforces.com/contest/671/submission/270548456
def main():
    n, k = MII()
    nums = [II() - 1 for _ in range(n)]

    dp = [1] * n
    fen = FenwickTree(n)

    for _ in range(k):
        fen.init()
        for i in range(n):
            fen.add(nums[i], dp[i])
            dp[i] = fen.sum(nums[i] - 1)

    print(sum(dp))