INF = 10**9
def main():
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    
    x,y = divmod(n, k)
    dp = [INF] * (y + 1)
    dp[0] = 0
    for i in range( k):
        for j in range(y,-1,-1):
            if j < y:
                dp[j + 1] = min(dp[j + 1], dp[j] + a[(i + 1) * x + j] - a[i * x + j])
            dp[j] += a[(i + 1)* x+j-1] - a[i*x+j]
    print(dp[-1])


main()