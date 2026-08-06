# Submission link: https://codeforces.com/gym/105190/submission/385833550
def main():
    t = II()
    outs = []
    
    M = 4 * 10 ** 5 + 5
    
    pr = list(range(M))
    
    for i in range(2, M):
        if pr[i] == i:
            for j in range(i, M, i):
                pr[j] = i
    
    def factors(x):
        ans = [1]
        
        while x > 1:
            p = pr[x]
            c = 0
            
            while x % p == 0:
                x //= p
                c += 1
            
            l = len(ans)
            
            for _ in range(l * c):
                ans.append(ans[-l] * p)
        
        return ans
    
    last_pos = [-inf] * M
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        dp = [0] * n
        
        for i in range(n):
            for f in factors(nums[i]):
                if i - last_pos[f] <= k:
                    dp[i] = fmax(dp[i], dp[last_pos[f]] + f)
                last_pos[f] = i
        
        outs.append(max(dp))
        
        for i in range(M):
            last_pos[i] = -inf
    
    print('\n'.join(map(str, outs)))