# Submission link: https://codeforces.com/contest/733/submission/300905347
def main():
    n = II()
    nums = LII()
    k = II()
    vals = LII()
    
    outs = []
    pt = 0
    cur = 0
    
    start_idx = 1
    for v in vals:
        l = pt
        while pt < n and cur < v:
            cur += nums[pt]
            pt += 1
        r = pt
        
        if cur != v: exit(print('NO'))
        
        if r - l > 1:
            ma = 0
            for i in range(l, r):
                if nums[i] > ma:
                    ma = nums[i]
            
            flg = False
            for i in range(l, r):
                if nums[i] == ma:
                    if i > l and nums[i] > nums[i - 1]:
                        flg = True
                        
                        for j in range(i - 1, l - 1, -1):
                            outs.append(f'{start_idx + j + 1 - l} L')
                        
                        for j in range(i + 1, r):
                            outs.append(f'{start_idx} R')
                        
                        break
                    
                    if i + 1 < r and nums[i] > nums[i + 1]:
                        flg = True
                        
                        for j in range(i + 1, r):
                            outs.append(f'{start_idx + i - l} R')
                        
                        for j in range(i - 1, l - 1, -1):
                            outs.append(f'{start_idx + j + 1 - l} L')
                        
                        break
            
            if not flg: exit(print('NO'))
        
        cur = 0
        start_idx += 1
    
    if pt < n: exit(print('NO'))
    
    print('YES')
    print('\n'.join(outs))