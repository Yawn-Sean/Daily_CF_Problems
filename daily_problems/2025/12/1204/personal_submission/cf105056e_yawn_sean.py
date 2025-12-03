# Submission link: https://codeforces.com/gym/105056/submission/351667929
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
    
        acc = [0] * (n + 1)
        for i in range(n):
            acc[i + 1] = acc[i] + nums[i]
    
        ans = 0
    
        stk = [n + 1]
        stk_acc = [0]
        
        for i in range(n, -1, -1):
            while stk[-1] != n + 1 and acc[i] >= acc[stk[-1]]:
                stk_acc.pop()
                stk.pop()
            
            stk_acc.append(stk_acc[-1] + (stk[-1] - i) * acc[i])
            stk.append(i)
            
            ans += stk_acc[-1] - (n + 1 - i) * acc[i]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))