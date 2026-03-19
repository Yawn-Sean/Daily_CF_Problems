# Submission link: https://codeforces.com/gym/106433/submission/367355356
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        vis = [0] * (n + 1)
        for x in nums: vis[x] = 1
        
        mapping = [0] * (n + 1)
        pt = 1
        
        for i in range(n):
            if mapping[nums[i]] == 0:
                mapping[nums[i]] = pt
                pt += 1
            
            nums[i] = mapping[nums[i]]
        
        outs.append(' '.join(map(str, nums)))
    
    print('\n'.join(outs))