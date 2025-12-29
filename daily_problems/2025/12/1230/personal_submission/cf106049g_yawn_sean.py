# Submission link: https://codeforces.com/gym/106049/submission/355667648
def main(): 
    t = II()
    outs = []
    mod = 998244353
    
    for _ in range(t):
        n, l, r = MII()
        block_cnt = n // l
        
        if block_cnt * r < n: outs.append('-1')
        else:
            ans = []
            for i in range(block_cnt):
                v = fmax(l, n - (block_cnt - 1 - i) * r)
                n -= v
                ans.append(v)
            
            v = 1
            for i in range(1, ans[0] + 1):
                v = v * i % mod
            
            outs.append(f'{len(ans)} {v}')
            
            cur = 1
            for x in ans:
                outs.append(f'{cur} {cur + x - 1}')
                cur += x
    
    print('\n'.join(outs))