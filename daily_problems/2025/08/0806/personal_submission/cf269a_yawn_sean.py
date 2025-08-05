# Submission link: https://codeforces.com/contest/269/submission/332503194
def main():
    n = II()
    ans = 0
    
    for _ in range(n):
        k, a = MII()
        
        ans = fmax(ans, k + 1)
        
        while a > 1:
            a = (a + 3) // 4
            k += 1
        
        ans = fmax(ans, k)
    
    print(ans)