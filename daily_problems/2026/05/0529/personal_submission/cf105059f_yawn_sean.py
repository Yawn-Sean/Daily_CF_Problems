# Submission link: https://codeforces.com/gym/105059/submission/376347548
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = 0
        
        acc = list(accumulate(nums, initial=0))
        
        cur = 0
        
        for i in range(n):
            cur += acc[n - i] - acc[i]
            ans += cur / (i + 1)
        
        outs.append(ans / (n * (n + 1) / 2))
    
    print('\n'.join(map(str, outs)))