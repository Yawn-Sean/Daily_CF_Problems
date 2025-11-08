# Submission link: https://codeforces.com/gym/106174/submission/347865031
def main(): 
    def f(x):
        start = 1
        d = 1
        ans = 0
        
        for _ in range(18):
            if start > x: break
            ans += fmin(start * 9, x - start + 1) * d
            start *= 10
            d += 1
        
        return ans
    
    n = II()
    k = II()
    
    l, r = 1, 10 ** 18
    
    while l <= r:
        mid = (l + r) // 2
        
        if f(mid + n - 1) - f(mid - 1) < k: l = mid + 1
        else: r = mid - 1
    
    print(l if f(l + n - 1) - f(l - 1) == k else -1)