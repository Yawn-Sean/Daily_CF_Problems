mii = lambda: map(int, input().split())
MOD = 10**9+7

def solve():
    m, n, k, x_offset, y_offset = mii()
    x1, y1, x2, y2 = mii()
    if x1 == x2 and y1 == y2:
        return pow(k, m*n, MOD)
    dx, dy = x2-x1+1, y2-y1+1
    if x_offset >= dx or y_offset >= dy:
        return pow(k, m*n-x_offset*y_offset, MOD)
    from math import gcd
    x_inter, y_inter = dx-x_offset, dy-y_offset
    ans1 = pow(k, m*n - dx*dy*2 + x_inter*y_inter, MOD)
    ans2 = pow(k, gcd(dx, x_inter)*gcd(dy, y_inter), MOD)
    return ans1 * ans2 % MOD

print(solve())