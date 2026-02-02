# Submission link: https://codeforces.com/gym/105400/submission/361164403
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        mi = min(nums)
        ma = max(nums)
        
        if mi == ma: outs.append(10 ** n)
        else:
            ans = 1
            for x in nums:
                if x == mi:
                    ans *= x
                elif x == ma:
                    ans *= 11 - x
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))