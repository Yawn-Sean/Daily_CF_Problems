'''
https://codeforces.com/gym/106439/submission/368350062
'''
MAXN = 200009
MOD = 1000000007
pa = list(accumulate(range(MAXN), lambda x, _: x * 2 % MOD, initial=1))
dp = [1] * MAXN
dp[0] = 0
for i in range(2, MAXN):
    dp[i] = (dp[i - 1] + 2 * dp[i - 2] + pa[i - 1]) % MOD

def solve(n: int) -> int:
    global dp
    return dp[n]
