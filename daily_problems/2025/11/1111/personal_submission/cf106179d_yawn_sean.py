# Submission link: https://codeforces.com/gym/106179/submission/348251835
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        v1 = []
        v2 = []
        
        for i in range(n):
            if (i < n // 2) ^ (nums[i] <= n // 2):
                v1.append(nums[i])
            else:
                v2.append(nums[i])
        
        if len(v1) and len(v2):
            outs.append('2')
            outs.append(f'{len(v1)} {" ".join(map(str, v1))}')
            outs.append(f'{len(v2)} {" ".join(map(str, v2))}')
        else:
            outs.append('1')
            outs.append(f'{n} {" ".join(map(str, nums))}')
    
    print('\n'.join(outs))