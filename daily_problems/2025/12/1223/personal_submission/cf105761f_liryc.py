'''
https://codeforces.com/gym/105761/submission/354636728
'''
def solve(n: int, p: int) -> int:
    if p == 1:
        return n - 1
    elif p > 20: 
        p = 20
    dp = [[1] * (n + 1) for _ in range(p + 1)]    
    for i in range(1, p + 1):
        for j in range(1, n + 1):
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]
            if dp[i][j] > n:
                dp[i][j] = n
    return bisect_left(dp[p], n)
