# Submission link: https://codeforces.com/gym/106628/submission/384689511
def main():
    t = II()
    outs = []
    
    inf = 10 ** 9
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        parent = [[-1] * n for _ in range(20)]
        mi = [[0] * n for _ in range(20)]
        ma = [[0] * n for _ in range(20)]
        
        for i in range(1, n):
            p, w = MII()
            p -= 1
            parent[0][i] = p
            mi[0][i] = w
            ma[0][i] = w
        
        for i in range(19):
            for j in range(n):
                if parent[i][j] != -1:
                    parent[i + 1][j] = parent[i][parent[i][j]]
                    mi[i + 1][j] = fmin(mi[i][j], mi[i][parent[i][j]])
                    ma[i + 1][j] = fmax(ma[i][j], ma[i][parent[i][j]])
        
        ans = [0] * n
        
        for i in range(n):
            cur = i
            cur_mi = inf
            cur_ma = -inf
            
            for j in range(19, -1, -1):
                if parent[j][cur] == -1: continue
                
                ncur_mi = fmin(cur_mi, mi[j][cur])
                ncur_ma = fmax(cur_ma, ma[j][cur])
                
                if ncur_ma - ncur_mi <= nums[i]:
                    cur = parent[j][cur]
                    cur_mi = ncur_mi
                    cur_ma = ncur_ma
    
            ans[i] += 1
            if cur: ans[parent[0][cur]] -= 1
        
        for i in range(n - 1, 0, -1):
            ans[parent[0][i]] += ans[i]
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))