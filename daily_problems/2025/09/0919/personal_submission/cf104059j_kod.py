s = input()
ans = 0
for x in permutations('hcds'):
    dp = [0] * 4
    for c in s:
        dp[x.index(c)] += 1
        dp[1] = max(dp[0], dp[1])
        dp[2] = max(dp[1], dp[2])
        dp[3] = max(dp[2], dp[3])
    ans = max(ans, dp[-1])
print(len(s) - ans)
