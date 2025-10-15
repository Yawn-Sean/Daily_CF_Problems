# Submission link: https://codeforces.com/contest/2071/submission/335493527
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, l, r = MII()
        nums = LII()
        
        if n % 2 == 0:
            v = 0
            for i in range(n // 2):
                v ^= nums[i]
            nums.append(v)
            n += 1
        
        total = reduce(xor, nums)
        
        def solve(x):
            if x <= n: return nums[x - 1]
            
            if x <= 2 * n:
                ans = 0
                for i in range(x // 2):
                    ans ^= nums[i]
                return ans
            
            v = x // 2
            if v % 2 == 0: return total ^ solve(v) 
            return total
        
        outs.append(solve(l))
    
    print('\n'.join(map(str, outs)))