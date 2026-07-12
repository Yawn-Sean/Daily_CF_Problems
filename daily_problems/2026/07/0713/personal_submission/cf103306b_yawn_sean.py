# Submission link: https://codeforces.com/gym/103306/submission/382203235
def main():
    n, m = MII()
    nums = LII()
    
    mod = 998244353
    f = Factorial(2 * 10 ** 5, mod)
    
    acc = [0] * (m + 2)
    pw = 1
    
    for i in range(m, -1, -1):
        cur = pw * f.combi(m, i) % mod
        pw = pw * (n - 1) % mod
        acc[i + 1] = cur
    
    rev_total = pow(pow(n, -1, mod), m, mod)
    
    for i in range(1, m + 2):
        acc[i] += acc[i - 1]
        acc[i] %= mod
    
    for i in range(m + 2):
        acc[i] = acc[i] * rev_total % mod
    
    ans = [0] * 10
    
    for x in nums:
        for i in range(1, 10):
            l, r = i, i
    
            for _ in range(6):
                vl = fmax(0, l - x)
                vr = fmin(m, r - x)
                
                l = l * 10
                r = r * 10 + 9
                
                if vl > vr: continue
                
                ans[i] += acc[vr + 1] - acc[vl]
                ans[i] %= mod
            
    print(*ans[1:], sep='\n')