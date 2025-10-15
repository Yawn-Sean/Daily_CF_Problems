# Submission link: https://codeforces.com/contest/1032/submission/302527236
def main():
    n = II()
    nums = LII()

    dp = [[-2] * n for _ in range(6)]

    for i in range(1, 6):
        dp[i][0] = -1

    for i in range(1, n):
        for j in range(1, 6):
            if dp[j][i - 1] != -2:
                for nj in range(1, 6):
                    if (nums[i] > nums[i - 1] and nj > j) or \
                        (nums[i] == nums[i - 1] and nj != j) or \
                        (nums[i] < nums[i - 1] and nj < j):
                        dp[nj][i] = j

    for i in range(1, 6):
        if dp[i][n - 1] != -2:
            ans = [i]
            for j in range(n - 1, 0, -1):
                ans.append(dp[ans[-1]][j])
            ans.reverse()
            print(' '.join(map(str, ans)))
            exit()

    print(-1)