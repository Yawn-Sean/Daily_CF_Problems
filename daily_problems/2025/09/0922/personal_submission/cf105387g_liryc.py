'''
https://codeforces.com/gym/105387/submission/339835934
'''
def solve(n: int, k_r: int, k_g: int, k_b: int) -> int:
    MOD = 1000000007
    d_r, d_g, d_b = [0] * (n + 1), [0] * (n + 1), [0] * (n + 1)
    d_r[1] = d_g[1] = d_b[1] = 1
    
    for i in range(2, n + 1):
        d_r[i] = d_g[i] = d_b[i] = d_r[i - 1] + d_g[i - 1] + d_b[i - 1]

        if i == k_r + 1: 
            d_r[i] -= 1
        elif i > k_r + 1: 
            d_r[i] -= d_g[i - k_r - 1] + d_b[i - k_r - 1]

        if i == k_g + 1: 
            d_g[i] -= 1
        elif i > k_g + 1: 
            d_g[i] -= d_r[i - k_g - 1] + d_b[i - k_g - 1]

        if i == k_b + 1: 
            d_b[i] -= 1
        elif i > k_b + 1: 
            d_b[i] -= d_r[i - k_b - 1] + d_g[i - k_b - 1]

        d_r[i] %= MOD
        d_g[i] %= MOD
        d_b[i] %= MOD
    return (d_r[n] + d_g[n] + d_b[n]) % MOD