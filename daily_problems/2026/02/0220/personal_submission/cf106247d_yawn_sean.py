# Submission link: https://codeforces.com/gym/106247/submission/363604689
def main(): 
    n = II()
    k = II()
    
    ans = n + 1
    
    for i in range(1, 10 ** 6 + 1):
        if n % i == 0:
            if i <= k: ans = fmax(ans, n + i)
            if n // i <= k: ans = fmax(ans, n + n // i)
    
    print(ans)