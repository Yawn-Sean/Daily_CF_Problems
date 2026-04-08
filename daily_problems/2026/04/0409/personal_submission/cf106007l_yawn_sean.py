# Submission link: https://codeforces.com/gym/106007/submission/370248214
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        nums = LII()
        
        total_or = reduce(ior, nums)
        op_must = 0
        
        ans = 0
        cur = -1
        
        for i in range(n):
            if nums[i] != total_or:
                op_must |= total_or - nums[i]
                if i > cur:
                    ans += 1
                    cur = i + m - 1
        
        q = II()
        for _ in range(q):
            x = II()
            if x & op_must != op_must: outs.append(-1)
            elif x & total_or == x or ans == 0: outs.append(ans)
            else: outs.append((n - 1) // m + 1)
    
    print('\n'.join(map(str, outs)))