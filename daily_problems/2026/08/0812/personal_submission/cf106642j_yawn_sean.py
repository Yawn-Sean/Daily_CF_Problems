# Submission link: https://codeforces.com/gym/106642/submission/386443314
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = 0
        cur = 0
    
        stk = [(-inf, -1, 0, 0)]
        
        for i in range(n):
            while stk[-1][0] > nums[i]:
                cur -= stk[-1][2]
                stk.pop()
            
            if stk[-1][0] != nums[i]:
                stk.append((nums[i], i, i - stk[-1][1], 0))
            else:
                val, idx, dp1, dp2 = stk.pop()
                cur -= dp1
                stk.append((nums[i], i, dp2 + i - idx, dp1))
            
            cur += stk[-1][2]
            ans += cur
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))