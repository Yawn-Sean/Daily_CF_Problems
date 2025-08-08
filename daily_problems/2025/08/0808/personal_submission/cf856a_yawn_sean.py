# Submission link: https://codeforces.com/contest/856/submission/332791388
def main():
    t = II()
    outs = []
    
    M = 10 ** 6 + 1
    used = [0] * M
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = []
        
        for i in range(1, M):
            if not used[i]:
                used[i] = 1
                ans.append(i)
                
                for j in range(n):
                    for k in range(j):
                        v = i + abs(nums[j] - nums[k])
                        if v < M:
                            used[v] = 1
                
                if len(ans) == n:
                    break
        
        for i in range(M):
            used[i] = 0
        
        outs.append('YES')
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))