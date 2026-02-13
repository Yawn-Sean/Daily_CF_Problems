# Submission link: https://codeforces.com/gym/104052/submission/362772082
def main(): 
    t = II()
    outs = []
    
    tmp = [[2, 1, 1, 0], [2, 0, 2, 0], [1, 1, 2, 1]]
    inf = 10 ** 9
    
    for _ in range(t):
        nums = LII()
        
        ans = inf
        for i in range(16):
            cur = 0
            for j in range(4):
                if i >> j & 1:
                    cur += nums[j]
            
            to_check = inf
            
            for j in range(3):
                val = 0
                for k in range(4):
                    if i >> k & 1:
                        val += tmp[j][k]
                to_check = fmin(to_check, val)
            
            if to_check: ans = fmin(ans, cur // to_check)
    
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))