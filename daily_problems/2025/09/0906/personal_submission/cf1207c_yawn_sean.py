# Submission link: https://codeforces.com/contest/1207/submission/336941468
def main():
    t = II()
    outs = []
    
    inf = 10 ** 16
    
    for _ in range(t):
        n, a, b = MII()
        nums = [int(c) for c in I()]
        
        dp0, dp1 = b, inf
        
        for x in nums:
            if x:
                dp0, dp1 = inf, dp1 + a + 2 * b
            else:
                dp0, dp1 = fmin(dp0 + a + b, dp1 + 2 * a + b), fmin(dp1 + a + 2 * b, dp0 + 2 * a + 2 * b)
        
        outs.append(dp0)
    
    print('\n'.join(map(str, outs)))