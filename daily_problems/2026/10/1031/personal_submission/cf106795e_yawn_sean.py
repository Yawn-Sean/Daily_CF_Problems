# Submission link: https://codeforces.com/gym/106795/submission/396639262
def main(): 
    n, r = MII()
    
    t, c = MII()
    
    g = 0
    mx = c
    
    for _ in range(n - 1):
        nt, nc = MII()
        
        g = math.gcd(g, (nt - t) * r - (nc - c))
        mx = max(mx, nc)
    
    if g == 0: print(mx + 1)
    else:
        ans = inf
        for i in range(1, 10 ** 6 + 5):
            if g % i == 0:
                if i > mx: ans = fmin(ans, i)
                if g // i > mx: ans = fmin(ans, g // i)
        
        print(ans if ans < inf else -1)