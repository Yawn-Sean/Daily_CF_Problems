# Submission link: https://codeforces.com/gym/102319/submission/393672080
def main():
    n = II()
    l, r = MII()
    nums = LII()
    
    inf = 10 ** 9
    
    dp = [inf] * (r + 1)
    dp[0] = 0
    
    for x in nums:
        for y in range(x, r + 1):
            dp[y] = fmin(dp[y], dp[y - x] + 1)
    
    cur_ans = sum(dp[l:r + 1])
    choice = 0
    
    for i in range(2, r + 1):
        new_ans = 0
        
        for x in range(l, r + 1):
            v = dp[x]
            for y in range(1, x // i + 1):
                v = fmin(v, dp[x - y * i] + y)
            new_ans += v
        
        if new_ans < cur_ans:
            cur_ans = new_ans
            choice = i
    
    print(choice)