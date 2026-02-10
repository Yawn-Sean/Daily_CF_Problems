# Submission link: https://codeforces.com/gym/104020/submission/362262581
def main(): 
    c, t, r = map(int, input().split())
    p = float(input())
    
    time = [0] * (c + 1)
    
    for i in range(c):
        time[i + 1] = (time[i] + 1 + p * r) / (1 - p)
    
    inf = 10 ** 18
    dp = [inf] * (c + 1)
    dp[0] = 0
    
    for i in range(1, c + 1):
        for j in range(i + 1):
            dp[i] = fmin(dp[i], dp[i - j] + time[j] + t)
    
    print(dp[c])