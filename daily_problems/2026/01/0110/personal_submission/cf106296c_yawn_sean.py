# Submission link: https://codeforces.com/gym/106296/submission/357051818
def main(): 
    def check(x):
        print(2, 2 * x - 1, flush=True)
        v1 = II()
        print(1, 2 * x, flush=True)
        v2 = II()
        return v1 == v2
    
    t = II()
    
    for _ in range(t):
        n = II()
        v = (n + 1) // 2
        
        l, r = 1, v - 1
        while l <= r:
            mid = (l + r) // 2
            
            if check(mid): l = mid + 1
            else: r = mid - 1
        
        print(3, 2 * r - 1, 2 * r + 1, flush=True)