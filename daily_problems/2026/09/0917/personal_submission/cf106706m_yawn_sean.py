# Submission link: https://codeforces.com/gym/106706/submission/390886489
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = n * (n - 1) // 2 - 1
        
        cur = 0
        for i in range(n):
            ans = fmax(ans, cur - nums[i])
            cur += nums[i]
        
        cur = 0
        for i in range(n - 1, -1, -1):
            ans = fmax(ans, cur - nums[i])
            cur += nums[i]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))