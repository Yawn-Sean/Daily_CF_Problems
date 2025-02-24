# Submission link: https://codeforces.com/contest/1510/submission/307069585
def main():
    n, d = MII()
    nums = LII()

    if d % 2:
        nums = [v for v in nums if v % 2]
    if d % 5:
        nums = [v for v in nums if v % 5]

    n = len(nums)

    inf = 10 ** 9 + 10

    dp = [[inf] * (n + 1) for _ in range(10)]
    dp[1][0] = 1

    prev = [[-1] * (n + 1) for _ in range(10)]

    for i in range(n):
        for j in range(10):
            if dp[j][i + 1] > dp[j][i] * nums[i]:
                dp[j][i + 1] = dp[j][i] * nums[i]
                prev[j][i + 1] = j
            
            nj = j * nums[i] % 10
            if dp[nj][i + 1] > dp[j][i]:
                dp[nj][i + 1] = dp[j][i]
                prev[nj][i + 1] = j

    if dp[d][n] < inf:
        ans = []
        cur_d = d
        
        for i in range(n, 0, -1):
            p = prev[cur_d][i]
            if dp[p][i - 1] == dp[cur_d][i] or nums[i - 1] == 1:
                cur_d = p
                ans.append(nums[i - 1])
        
        if len(ans):
            print(len(ans))
            print(*ans)
        else:
            print(-1)
            
    else:
        print(-1)