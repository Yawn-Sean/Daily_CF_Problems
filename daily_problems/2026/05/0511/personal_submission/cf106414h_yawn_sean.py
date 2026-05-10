# Submission link: https://codeforces.com/gym/106414/submission/374074121
def main(): 
    s = I()
    if s == 'first':
        t = II()
        outs = []
        
        for _ in range(t):
            n, m = MII()
            nums = LII()
            
            path = [[] for _ in range(n)]
            for _ in range(m):
                u, v = GMI()
                path[u].append(v)
                path[v].append(u)
            
            cols = [-1] * n
            
            for i in range(n):
                if cols[i] == -1:
                    cols[i] = 0
                    que = [i]
                    
                    for u in que:
                        for v in path[u]:
                            if cols[v] == -1:
                                cols[v] = cols[u] ^ 1
                                que.append(v)
            
            c1 = sum(cols)
            c0 = n - c1
            
            if c0 <= c1:
                outs.append(str(c0))
                outs.append(' '.join(str(nums[i]) for i in range(n) if cols[i] == 0))
            else:
                outs.append(str(c1))
                outs.append(' '.join(str(nums[i]) for i in range(n) if cols[i] == 1))
        
        print('\n'.join(outs))
    else:
        t = II()
        outs = []
        
        for _ in range(t):
            n, m, k = MII()
            nums = LII() if k else []
            
            path = [[] for _ in range(n)]
            for _ in range(m):
                u, v = GMI()
                path[u].append(v)
                path[v].append(u)
            
            cols = [-1] * n
            
            for i in range(n):
                if cols[i] == -1:
                    cols[i] = 0
                    que = [i]
                    
                    for u in que:
                        for v in path[u]:
                            if cols[v] == -1:
                                cols[v] = cols[u] ^ 1
                                que.append(v)
            
            c1 = sum(cols)
            c0 = n - c1
            
            ans = [0] * n
            pt = 0
            
            if c0 <= c1:
                for i in range(n):
                    if cols[i] == 0:
                        ans[i] = nums[pt]
                        pt += 1
            else:
                for i in range(n):
                    if cols[i] == 1:
                        ans[i] = nums[pt]
                        pt += 1
            
            choices = [[0] * n for _ in range(2)]
            
            for i in range(n):
                if ans[i] == 0:
                    if len(path[i]) == 0:
                        ans[i] = 1
                    else:
                        notvis = [1] * 4
                        for j in path[i]:
                            notvis[ans[j]] = 0
                        
                        tmp = []
                        for j in range(1, 4):
                            if notvis[j]:
                                tmp.append(j)
    
                        if len(tmp) == 1: ans[i] = tmp[0]
                        else:
                            choices[0][i] = tmp[0]
                            choices[1][i] = tmp[1]
            
            check = TwoSat(n)
            
            for i in range(n):
                if not ans[i]:
                    for j in path[i]:
                        if ans[j]:
                            for vi in range(2):
                                if choices[vi][i] == ans[j]:
                                    check.add_clause(i, vi ^ 1, i, vi ^ 1)
                        else:
                            for vi in range(2):
                                for vj in range(2):
                                    if choices[vi][i] == choices[vj][j]:
                                        check.add_clause(i, vi ^ 1, j, vj ^ 1)
            
            check.satisfiable()
            check_ans = check.answer
            
            for i in range(n):
                if ans[i] == 0:
                    ans[i] = choices[check_ans[i]][i]
            
            outs.append(' '.join(map(str, ans)))
        
        print('\n'.join(outs))