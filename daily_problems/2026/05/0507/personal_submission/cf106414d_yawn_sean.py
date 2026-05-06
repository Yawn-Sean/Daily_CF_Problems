# Submission link: https://codeforces.com/gym/106414/submission/373700672
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        nums[k - 1], nums[-1] = nums[-1], nums[k - 1]
        
        vis = [0] * (n + 1)
        for i in range(n - 1):
            vis[nums[i]] = 1
        
        mex = 0
        while vis[mex]:
            mex += 1
        
        outs.append('-1 -1' if nums[-1] >= mex else f'{k} {n}')
    
    print('\n'.join(outs))