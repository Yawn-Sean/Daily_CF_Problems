# Submission link: https://codeforces.com/contest/811/submission/287132216
def main():
    n = II()
    nums = LII()

    ls = [0] * 5001
    rs = [0] * 5001

    for i in range(n - 1, -1, -1):
        ls[nums[i]] = i

    for i in range(n):
        rs[nums[i]] = i

    dp = [0] * (n + 1)
    vis = [0] * 5001

    for i in range(n):
        r = 0
        v = 0
        
        for j in range(i, n):
            if ls[nums[j]] < i:
                break
            
            if not vis[nums[j]]:
                vis[nums[j]] = 1
                v ^= nums[j]
            
            if rs[nums[j]] > r:
                r = rs[nums[j]]
            
            if j == r:
                dp[j + 1] = fmax(dp[j + 1], dp[i] + v)
        
        dp[i + 1] = fmax(dp[i + 1], dp[i])

        for j in range(5001):
            vis[j] = 0

    print(dp[n])