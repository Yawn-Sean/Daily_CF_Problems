def main():
    n = int(input())
    p = list(map(lambda x: int(x) - 1, input().split()))
    mod = 10 ** 9 + 7
    dp = [0] * (n +1)
    for i in range(n):
        dp[i + 1] = (dp[i] * 2 - dp[p[i]] + 2) % mod
    print(dp[-1])


main()