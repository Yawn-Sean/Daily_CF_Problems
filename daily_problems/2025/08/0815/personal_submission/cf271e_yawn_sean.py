# Submission link: https://codeforces.com/contest/271/submission/333938415
def main():
    n, m = MII()
    nums = LGMI()
    
    g = math.gcd(*nums)
    g //= g & -g
    
    ans = 0
    
    def solve(x):
        res = 0
        v = x
        while v <= m:
            res += m - v
            v *= 2
        return res
    
    for i in range(1, 100000):
        if i > g // i: break
        
        if g % i == 0:
            ans += solve(i)
            if i != g // i:
                ans += solve(g // i)
    
    print(ans)