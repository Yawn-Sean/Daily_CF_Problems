# Submission link: https://codeforces.com/gym/106531/submission/374908426
def main():  
    n = II()
    nums = LII()
    
    k = sum(nums)
    
    for i in range(n):
        nums[i] *= n
    
    print(k - 1)
    
    v1 = [0] * n
    v2 = [0] * n
    w = [0] * n
    
    for i in range(n):
        mi_idx = -1
        
        for j in range(n):
            if nums[j] and (mi_idx == -1 or nums[j] < nums[mi_idx]):
                mi_idx = j
        
        if nums[mi_idx] >= k:
            v1[i] = mi_idx
            v2[i] = mi_idx
            w[i] = 0
        else:
            to_pair = -1
            for j in range(n):
                if j != mi_idx and nums[j] and nums[mi_idx] + nums[j] >= k:
                    to_pair = j
            
            v1[i] = mi_idx
            v2[i] = to_pair
            w[i] = nums[mi_idx]
        
        nums[v1[i]] -= w[i]
        nums[v2[i]] -= k - w[i]
    
    print(*(x + 1 for x in v1))
    print(*(x + 1 for x in v2))
    print(*w)