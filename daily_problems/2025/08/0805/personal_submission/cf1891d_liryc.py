'''
https://codeforces.com/problemset/submission/1891/332485022
'''
# enumerations
def solve(l: int, r: int) -> int:
    MOD = 1000000007
    f = l.bit_length() - 1
    n = 1 << f + 1
    g, m = 0, f
    while m <= l:
        g, m = g + 1, m * f
    ans = 0
    while True:
        if r < n and r < m:
            ans = (ans + g * (r - l + 1)) % MOD
            return ans
        if n <= m:
            ans = (ans + g * (n - l)) % MOD
            l, f, n = n, f + 1, n << 1
            g, m = 0, f
            while m <= l:
                g, m = g + 1, m * f    
        else:
            ans = (ans + g * (m - l)) % MOD
            l, g, m = m, g + 1, m * f        
