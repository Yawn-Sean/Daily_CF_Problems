# Submission link: https://codeforces.com/gym/104017/submission/387767130
def main():
    t = II()
    outs = []
    
    inf = 10 ** 6
    
    for _ in range(t):
        n, a, b = MII()
        nums = LII()
        
        a -= 1
        b -= 1
        
        dp = [inf] * n
        dp[a] = 0
        
        flg = True
        
        while flg:
            flg = False
            
            def solve():
                global flg
                
                seg = SegTree(fmin, inf, n)
                updates = [[] for _ in range(n)]
                
                for i in range(n):
                    for x in updates[i]:
                        seg.set(x, inf)
                    
                    v = seg.prod(fmax(0, i - nums[i]), i)
                    if v + 1 < dp[i]:
                        flg = True
                        dp[i] = v + 1
                    
                    seg.set(i, dp[i])
                    
                    if i + nums[i] + 1 < n:
                        updates[i + nums[i] + 1].append(i)
            
            for _ in range(2):
                solve()
                nums.reverse()
                dp.reverse()
        
        outs.append(dp[b])
    
    print('\n'.join(map(str, outs)))