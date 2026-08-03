# Submission link: https://codeforces.com/gym/106632/submission/385335312
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        nums = LII()
        
        def f(x):
            if x < 0: return 0
            
            l = 0
            r = 0
            
            cur_sum = 0
            cur_xor = 0
            
            ans = 0
            
            while l < n:
                r = fmax(l, r)
                
                while cur_sum - cur_xor <= x and r < n:
                    if r < n - 1:
                        v = nums[r] ^ nums[r + 1]
                        cur_sum += v
                        cur_xor ^= v
                    r += 1
                
                ans += r - l
                
                if l < n - 1:
                    v = nums[l] ^ nums[l + 1]
                    cur_sum -= v
                    cur_xor ^= v
                
                l += 1
            
            return ans
        
        outs.append(f(m) - f(m - 1))
    
    print('\n'.join(map(str, outs)))