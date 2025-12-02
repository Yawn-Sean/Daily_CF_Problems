'''
https://codeforces.com/gym/105316/submission/351565933
'''

MOD = 998244353
maxn = 100000
fac = Factorial(maxn + 1, MOD)
    
def solve(n: int) -> int:
    global fac
    ans = 0
    for k in range(1, n + 1):
        ans = (ans + (n + 1) * fac.inv(k + 1)) % MOD
    return ans
