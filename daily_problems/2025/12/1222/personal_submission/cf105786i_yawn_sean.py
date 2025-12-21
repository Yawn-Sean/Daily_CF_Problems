# Submission link: https://codeforces.com/gym/105786/submission/354440847
def main(): 
    M = 3 * 10 ** 5
    
    pr = list(range(M + 1))
    
    for i in range(2, M + 1):
        if pr[i] == i:
            for j in range(i, M + 1, i):
                pr[j] = i
    
    def get_prime_factors(x):
        ans = []
        
        while x > 1:
            p = pr[x]
            ans.append(p)
            
            while x % p == 0:
                x //= p
        
        return ans
    
    t = II()
    outs = []
    
    vis = [-1] * (M + 1)
    vis_target = [-1] * (M + 1)
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = 0
        to_delete = 0
        
        for i, x in enumerate(nums):
            tmp = get_prime_factors(x)
            
            flg = True
            pos = i
            for v in tmp:
                if vis[v] != -1:
                    pos = fmin(pos, vis[v])
                    flg = False
                else:
                    vis[v] = i
    
            if flg:
                ans += 1
                for v in tmp:
                    vis_target[v] = i
            else:
                nvis = set()
                
                for v in tmp:
                    if vis_target[v] > pos:
                        nvis.add(vis_target[v])
    
                to_delete = fmax(to_delete, len(nvis))
        
        outs.append(ans - to_delete)
        
        for x in nums:
            tmp = get_prime_factors(x)
            for v in tmp:
                vis[v] = -1
                vis_target[v] = -1
    
    print('\n'.join(map(str, outs)))