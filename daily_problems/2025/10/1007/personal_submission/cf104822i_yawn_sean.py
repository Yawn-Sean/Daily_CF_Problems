# Submission link: https://codeforces.com/gym/104822/submission/342369376
def main():
    M = 40000
    is_prime = [1] * (M + 1)
    prs = []
    
    for i in range(2, M + 1):
        if is_prime[i]:
            prs.append(i)
            for j in range(i * 2, M + 1, i):
                is_prime[j] = 0
    
    t = II()
    outs = []
    
    for _ in range(t):
        a = II()
        
        va = a
        vals = {}
        for p in prs:
            if p * p > va: break
            if va % p == 0:
                vals[p] = 0
                while va % p == 0:
                    vals[p] += 1
                    va //= p
        
        if va > 1:
            vals[va] = 1
        
        factors = [1]
        
        for x in vals:
            c = vals[x]
            k = len(factors)
            for i in range(c * k):
                factors.append(factors[i] * x)
    
        factors.sort()
        
        ans = a * a - a
        
        for i in range(len(factors) - 1):
            val = factors[i] * factors[len(factors) - 2 - i]
            ans = fmin(ans, a * a // val - a)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))