# Submission link: https://codeforces.com/gym/106225/submission/362407913
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        
        lsts = []
        for _ in range(n):
            lsts.append(LII())
    
        if n % 2 == 0:
            vis = [0] * (n * m // 2 + 1)
            
            ans = []
            for x in lsts:
                if vis[x[0]]: continue
                vis[x[0]] = 1
                ans.extend(x)
            
            outs.append(' '.join(map(str, ans)))
        
        else:
            next_pos = [0] * (n * m // 2 + 1)
            idxs = [0] * (n * m // 2 + 1)
    
            for i, lst in enumerate(lsts):
                idxs[lst[0]] = i
                next_pos[lst[0]] = lst[m // 2]
            
            ans = []
            
            cur = lsts[0][0]
            for _ in range(n):
                ans.extend(lsts[idxs[cur]][:m // 2])
                cur = next_pos[cur]
            
            outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(map(str, outs)))