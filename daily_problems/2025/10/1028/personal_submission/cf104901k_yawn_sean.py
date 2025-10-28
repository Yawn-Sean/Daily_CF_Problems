# Submission link: https://codeforces.com/gym/104901/submission/345966308
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        for i in range(n):
            nums[i] -= i
        
        vals = sorted(nums)
        
        fen_cnt = FenwickTree(n)
        fen_sum = FenwickTree(n)
        
        cnt = 0
        tot = 0
        
        l = 0
        r = -1
        
        ans = 0
        
        while l < n:
            while r < n:
                r += 1
                if r == n: break
                
                p = bisect.bisect_left(vals, nums[r])
                fen_cnt.add(p, 1)
                fen_sum.add(p, nums[r])
                
                cnt += 1
                tot += nums[r]
                pos = fen_cnt.bisect_min_larger((cnt + 1) // 2)
    
                left_cnt = fen_cnt.rsum(0, pos)
                left_sum = fen_sum.rsum(0, pos)
                
                right_cnt = cnt - left_cnt
                right_sum = tot - left_sum
                
                total = (left_cnt * vals[pos] - left_sum) + (right_sum - right_cnt * vals[pos])
                if total > k: break
            
            ans = fmax(ans, r - l)
            
            p = bisect.bisect_left(vals, nums[l])
            
            fen_cnt.add(p, -1)
            fen_sum.add(p, -nums[l])
            
            cnt -= 1
            tot -= nums[l]
            
            l += 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))