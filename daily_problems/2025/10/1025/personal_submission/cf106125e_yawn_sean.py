# Submission link: https://codeforces.com/gym/106125/submission/345474236
def main(): 
    def query(l, r):
        print(l + 2, r + 1, flush=True)
        nums = LII()
        if II() >= 70: exit()
        return nums
    
    n = II()
    nums = [0] * n
    
    while True:
        cur_mi = 0
        mi_idx = -1
        
        cur = 0
        
        max_seg = 0
        l, r = -1, 0
        
        for i in range(n):
            cur += -1 if nums[i] else 1
            if cur < cur_mi:
                cur_mi = cur
                mi_idx = i
            
            if cur - cur_mi > max_seg:
                max_seg = cur - cur_mi
                l, r = mi_idx, i
        
        nums = query(l, r)