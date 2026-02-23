# Submission link: https://codeforces.com/gym/104523/submission/364014533
def main(): 
    t = II()
    outs = []
    
    def check(x):
        ans = 0
        while x:
            ans += x
            x //= 10
        return ans
    
    for _ in range(t):
        n = II()
        l, r = 1, 10 ** 18
        
        while l <= r:
            mid = (l + r) // 2
            
            if check(mid) > n: r = mid - 1
            else: l = mid + 1
        
        outs.append(n - r)
    
    print('\n'.join(map(str, outs)))