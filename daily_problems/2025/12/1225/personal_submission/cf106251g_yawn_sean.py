# Submission link: https://codeforces.com/gym/106251/submission/354889624
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, b = MII()
        nums = LII()
        
        if sum(nums) % (b - 1): outs.append('NO')
        else:
            outs.append('YES')
            
            res = []
            
            cur = 0
            for x in nums:
                cur = cur * b + x
                res.append(cur // (b - 1))
                cur %= b - 1
            
            outs.append(str(n + 2))
            outs.append('1 0 ' + ' '.join(map(str, res)))
            outs.append('1 ' + ' '.join(map(str, res)) + ' 0')
    
    print('\n'.join(outs))