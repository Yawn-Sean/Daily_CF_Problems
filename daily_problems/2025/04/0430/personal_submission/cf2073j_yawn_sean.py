# Submission link: https://codeforces.com/contest/2073/submission/317795435
def main():
    n = II()
    nums = LGMI()

    pos = [0] * n
    for i in range(n):
        pos[nums[i]] = i

    inf = 10 ** 9
    dp = [[0] * n for _ in range(n)]

    for diff in range(1, n):
        for i in range(n - diff):
            j = i + diff
            dp[i][j] = inf
            for sep in range(i, j):
                dp[i][j] = fmin(dp[i][j], dp[i][sep] + dp[sep + 1][j] + abs(pos[i] - pos[sep + 1]))

    print(dp[0][n - 1])