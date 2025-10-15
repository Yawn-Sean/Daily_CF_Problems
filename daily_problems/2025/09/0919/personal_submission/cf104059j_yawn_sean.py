# Submission link: https://codeforces.com/gym/104059/submission/339226877
def main():
    s = I()
    ans = 0
    
    for p in permutations('hdcs'):
        dp = [0] * 4
        for c in s:
            dp[p.index(c)] += 1
            dp[1] = fmax(dp[1], dp[0])
            dp[2] = fmax(dp[2], dp[1])
            dp[3] = fmax(dp[3], dp[2])
        ans = fmax(ans, dp[3])
    
    print(len(s) - ans)