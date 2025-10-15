def main():
    n,p,t = input().split()
    n = int(n)
    p = float(p)
    t = int(t)
    dp = [0] * (n + 1)
    dp[0] = 1
    for _ in range(t):
        for j in range(n-1, -1, -1):
            dp[j+1] += dp[j] * p
            dp[j] *= (1 - p)
    ans = 0
    for i,v in enumerate(dp):
        ans +=  v * i
    print(ans)

main()
            
