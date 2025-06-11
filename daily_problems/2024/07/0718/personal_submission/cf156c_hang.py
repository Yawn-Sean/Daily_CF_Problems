from functools import cache
def main():
    s = input()
    n = len(s)
    tot = sum(ord(c) - ord('a') for c in s)
    print(dp[n][tot] - 1 if dp[n][tot] else mod-1)
mod = 10 ** 9 + 7
dp = [[0] * (2501) for _ in range(101)]
dp[0][0] = 1
dp_pre = [0] * 2502
for i in range(1, 101):
    for j in range(2501):
        dp_pre[j + 1] = dp_pre[j] + dp[i - 1][j]
        dp_pre[j + 1] %= mod
    for j in range(25 * i + 1):
        dp[i][j] = (dp_pre[j + 1] - dp_pre[max(j - 25,0)]) % mod

t = int(input())
for _ in range(t):
    main()