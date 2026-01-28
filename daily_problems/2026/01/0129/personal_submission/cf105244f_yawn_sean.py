# Submission link: https://codeforces.com/gym/105244/submission/360271544
def main(): 
    n = II()
    k = II()
    
    nums = LII()
    vals = LII()
    
    ops = [1000] * 1001
    ops[0] = ops[1] = 0
    
    for i in range(1, 1001):
        for j in range(1, 1001):
            ni = i + i // j
            if ni <= 1000:
                ops[ni] = fmin(ops[ni], ops[i] + 1)
    
    dp = [0] * 12001
    
    for i in range(n):
        x = ops[nums[i]]
        y = vals[i]
        
        for j in range(12000, x - 1, -1):
            dp[j] = fmax(dp[j], dp[j - x] + y)
    
    print(max(dp[:k + 1]))