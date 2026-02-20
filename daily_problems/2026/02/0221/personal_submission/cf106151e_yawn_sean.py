# Submission link: https://codeforces.com/gym/106151/submission/363693940
def main(): 
    n, b = MII()
    xs = LII()
    ys = LII()
    
    inf = 2 * 10 ** 9
    dp = [inf] * (n + 1)
    dp[0] = 0
    
    order = sorted(range(n), key=lambda x: -ys[x])
    
    for i in range(n):
        idx = order[i]
        x = xs[idx]
        y = ys[idx]
        
        for j in range(i, -1, -1):
            dp[j + 1] = fmin(dp[j + 1], dp[j] + x + y * j)
    
    for i in range(n, -1, -1):
        if dp[i] <= b:
            print(i, dp[i])
            break