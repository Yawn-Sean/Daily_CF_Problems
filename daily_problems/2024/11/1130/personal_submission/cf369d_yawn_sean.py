# Submission link: https://codeforces.com/contest/369/submission/293926622
def main():
    n, k = MII()
    nums = LII()

    def f(i, j):
        return i * (n + 2) + j

    must_kill = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        must_kill[i] = must_kill[i + 1] | (nums[i] == 100)

    cant_kill = [1] * (n + 1)
    for i in range(n - 1, -1, -1):
        cant_kill[i] = cant_kill[i + 1] & (nums[i] == 0)

    dp = [4000] * ((n + 2) * (n + 2))
    dp[f(0, 1)] = 0

    for i in range(n):
        for j in range(i + 1, n):
            if dp[f(i, j)] < n:
                if not must_kill[j] and nums[i]:
                    dp[f(i, j + 1)] = fmin(dp[f(i, j + 1)], dp[f(i, j)] + 1)
                if not cant_kill[j] and nums[i] < 100:
                    dp[f(j, j + 1)] = fmin(dp[f(j, j + 1)], dp[f(i, j)] + 1)
                if not cant_kill[j] and nums[i]:
                    dp[f(j + 1, j + 2)] = fmin(dp[f(j + 1, j + 2)], dp[f(i, j)] + 1)

    ans = 0
    for i in range(n + 1):
        for j in range(n + 2):
            if dp[f(i, j)] <= k:
                ans += 1

    print(ans)