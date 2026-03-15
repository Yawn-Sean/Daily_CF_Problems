# Submission link: https://codeforces.com/gym/106259/submission/366808557
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        nums.sort()
        outs.append(min(nums[i] ^ nums[i - 1] for i in range(1, n)))
    
    print('\n'.join(map(str, outs)))