# Submission link: https://codeforces.com/gym/106177/submission/348254906
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = 0
        
        cnt = [[0] * (2 * n + 5) for _ in range(2)]
        cur = n + 2
        msk = 0
        
        for x in nums:
            cnt[msk][cur] += 1
            
            if x % 2:
                msk ^= 1
                cur -= 1
            else:
                cur += 1
            
            ans += cnt[msk][cur - 1] + cnt[msk ^ 1][cur + 1]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))