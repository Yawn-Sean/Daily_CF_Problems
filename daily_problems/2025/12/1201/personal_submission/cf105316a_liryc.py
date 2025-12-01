'''
https://codeforces.com/gym/105316/submission/351425365
'''
def solve(n: int, a: list[int]) -> int:
    MOD = 1000000007
    limit = sum(a) + 1 >> 1 
    if any(x >= limit for x in a):
        return 0
    la = [0] * n 
    s, i = 0, 0
    for j, x in enumerate(a):
        s += x
        while s >= limit:
            s -= a[i]
            i += 1
        la[j] = i
    dp = [0] * (n + 1)
    pre = [0] * (n + 1) 
    pre[0] = dp[0] = 1
    for i in range(0, n):
        dp[i + 1] = pre[i] - pre[la[i] - 1]
        pre[i + 1] = (pre[i] + dp[i + 1]) % MOD
    return dp[-1] % MOD
