# Submission link: https://codeforces.com/gym/105327/submission/361169232
def main(): 
    n = II()
    nums = LII()
    
    total = sum(nums)
    
    if total % 2:
        print(-1)
    else:
        M = total // 2
    
        dp = [-2] * (M + 1)
        dp[0] = -1
        
        for i in range(n):
            x = nums[i]
            
            for j in range(M, x - 1, -1):
                if dp[j - x] != -2 and dp[j] == -2:
                    dp[j] = i
        
        if dp[M] == -2:
            print(-1)
        else:
            vis = [0] * n
            cur = M
            
            while cur:
                vis[dp[cur]] = 1
                cur -= nums[dp[cur]]
            
            v1 = [nums[i] for i in range(n) if vis[i]]
            v2 = [nums[i] for i in range(n) if not vis[i]]
            
            s1 = s2 = 0
            pt1 = pt2 = 0
            
            ans = []
            
            while pt1 < len(v1) or pt2 < len(v2):
                if s1 <= s2:
                    s1 += v1[pt1]
                    ans.append(v1[pt1])
                    pt1 += 1
                else:
                    s2 += v2[pt2]
                    ans.append(v2[pt2])
                    pt2 += 1
            
            print(*ans)