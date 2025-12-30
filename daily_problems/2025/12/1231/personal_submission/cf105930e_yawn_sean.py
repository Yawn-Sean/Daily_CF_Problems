# Submission link: https://codeforces.com/gym/105930/submission/355862405
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        ma = max(nums)
        acc_cnt = [0] * (ma + 1)
        
        for x in nums:
            acc_cnt[x] += 1
        
        for i in range(ma):
            acc_cnt[i + 1] += acc_cnt[i]
        
        total = sum(nums) + k
        
        def check(x):
            if x >= ma: return acc_cnt[ma] * x <= total
            
            val = 0
            for i in range(0, ma + 1, x):
                l = i
                r = fmin(i + x, ma)
                val += (acc_cnt[r] - acc_cnt[l]) * (i + x)
            
            return val <= total
    
        ans = 0
        
        for i in range(1, 10 ** 6 * 2):
            if i * i > total: break
            if total % i == 0:
                if check(i): ans = fmax(ans, i)
                if check(total // i): ans = fmax(ans, total // i)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))