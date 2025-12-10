# Submission link: https://codeforces.com/gym/106033/submission/352774076
def main(): 
    n, k = MII()
    n -= 1
    mod = 998244353
    
    f = Factorial(2 * n, mod)
    
    ans = 0
    for i in range(n - k - 1, n + k + 1):
        ans += f.combi(2 * n, i)
        ans %= mod
    
    print(ans)