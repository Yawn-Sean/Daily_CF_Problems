'''
https://codeforces.com/gym/105845/submission/353814262
'''
def solve(n: int) -> int: 
    MOD = 1000000007
    dp0, dp1 = [0] * (n + 1), [0] * (n + 1)
    dp0[0] = 1
    ans = 0
    for i in range(1, n + 1):
        ca = [0] * i
        p = 0
        for j in range(n + 1):
            p = (p + j) % i
            dp1[j] = ca[p]
            ca[p] = (ca[p] + dp0[j]) % MOD
        dp0, dp1 = dp1, dp0
        ans = (ans + dp0[-1]) % MOD
    return ans
