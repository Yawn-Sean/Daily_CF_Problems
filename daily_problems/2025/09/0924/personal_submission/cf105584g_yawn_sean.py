# Submission link: https://codeforces.com/gym/105584/submission/340017865
def main():
    outs = []
    t = 0
    
    while True:
        t += 1
        n = II()
        if n == 0:
            break
    
        nums = LII()
        
        if sum(nums) % 2: outs.append('No')
        else:
            ans = [0] * n
            
            idxs = []
            even_idx = -1
            
            for i in range(n):
                if nums[i] % 2:
                    idxs.append(i)
                elif even_idx == -1:
                    even_idx = i
                else:
                    ans[i] = nums[i] // 2
            
            if even_idx >= 0:
                outs.append('Yes')
                idxs.append(even_idx)
                
                cur = 0
                for i in idxs:
                    cur = nums[i] - cur
                
                cur //= 2
                for i in idxs:
                    ans[i] = cur
                    cur = nums[i] - cur
                
                outs.append(' '.join(map(str, ans)))
                outs.append(' '.join(map(str, (nums[i] - ans[i] for i in range(n)))))
            
            else:
                k = len(idxs)
                M = 300 * k // 2
                dp = [[-2] * (M + 1) for _ in range(k // 2 + 1)]
                dp[0][0] = -1
                
                for i in idxs:
                    for j in range(k // 2 - 1, -1, -1):
                        for v in range(M, -1, -1):
                            if dp[j][v] != -2 and v + 150 + nums[i] <= M and dp[j + 1][v + 150 + nums[i]] == -2:
                                dp[j + 1][v + 150 + nums[i]] = i
                
                total = sum(nums[idx] + 150 for idx in idxs) // 2
                if dp[k // 2][total] == -2:
                    outs.append('No')
                else:
                    outs.append('Yes')
                    vis = [0] * k
                    
                    i1 = []
                    i2 = []
                    cur = total
                    
                    for i in range(k // 2, 0, -1):
                        i1.append(dp[i][cur])
                        vis[dp[i][cur]] = 1
                        cur -= 150 + nums[dp[i][cur]]
                    
                    for i in range(k):
                        if not vis[i]:
                            i2.append(i)
    
                    cur = 0
                    for i in range(k // 2):
                        v1 = i1[i]
                        cur = nums[v1] - cur
                        ans[v1] = cur
                        v2 = i2[i]
                        cur = nums[v2] - cur
                        ans[v2] = cur
                    
                    outs.append(' '.join(map(str, ans)))
                    outs.append(' '.join(map(str, (nums[i] - ans[i] for i in range(n)))))
    
    print('\n'.join(outs))