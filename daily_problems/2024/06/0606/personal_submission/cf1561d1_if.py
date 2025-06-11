def solve():
    dp = [0] * (n+1)
    dp[1] = s = 1
    for i in range(2, n+1):
        v = s
        b = int(i ** 0.5)
        b += 1 if i ** 0.5 % 1 else 0
        for j in range(2, b):
            v += dp[i // j]
        for j in range(1, i//b + 1):
            v += dp[j] * (i//j - i // (j+1))
        dp[i] = v % m
        s = (s + dp[i]) % m
    return dp[n]


n, m=map(int,input().split())
print(solve())
