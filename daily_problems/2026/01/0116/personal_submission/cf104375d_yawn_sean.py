# Submission link: https://codeforces.com/gym/104375/submission/357906993
def main(): 
    n, q = MII()
    nums = LII()
    nums.sort()
    
    outs = []
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            v = query[1]
            
            if v > nums[-1]: nums.append(v)
            else:
                p = bisect.bisect_right(nums, v)
                if p > 0 and nums[p - 1] == v: continue
                else: nums[p] = v
        
        else:
            l = query[1]
            r = query[2]
            outs.append(bisect.bisect_right(nums, r) - bisect.bisect_left(nums, l))
    
    print('\n'.join(map(str, outs)))