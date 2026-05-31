# Submission link: https://codeforces.com/gym/106523/submission/376785746
def main():
    n = II()
    ds = LII()
    probs = LFI()
    
    l, r = 0, 10 ** 9
    
    for _ in range(100):
        mid = (l + r) / 2
        cur = mid
        
        for i in range(n - 1, -1, -1):
            cur = probs[i] * fmin(cur + 1, ds[i]) + (1 - probs[i]) * (cur + 1)
    
        if cur < mid: r = mid
        else: l = mid
    
    print((l + r) / 2)