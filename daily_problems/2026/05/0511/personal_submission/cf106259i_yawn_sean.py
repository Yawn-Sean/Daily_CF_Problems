# Submission link: https://codeforces.com/gym/106259/submission/374074276
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        outs.append('YES' if nums[0] + nums[-1] == 3 else 'NO')
    
    print('\n'.join(outs))