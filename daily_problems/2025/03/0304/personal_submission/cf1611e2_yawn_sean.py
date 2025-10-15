# Submission link: https://codeforces.com/contest/1611/submission/308862369
def main():
    t = II()
    outs = []

    for _ in range(t):
        I()
        
        n, k = MII()
        nums = LII()
        
        path = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            u, v = MII()
            path[u].append(v)
            path[v].append(u)
        
        stk = [1]
        cur_path = []
        
        note = [0] * (n + 1)
        
        while stk:
            u = stk.pop()
            if u > 0:
                cur_path.append(u)
                note[u] = cur_path[len(cur_path) // 2]
                
                stk.append(~u)
                for v in path[u]:
                    if not note[v]:
                        stk.append(v)
            else:
                cur_path.pop()
        
        control = [-1] * (n + 1)
        for u in nums:
            control[note[u]] = u
        
        vis = [0] * (n + 1)
        stk = [1]
        
        while stk:
            u = stk.pop()
            vis[u] = 1
            
            if control[u] != -1:
                continue
            
            for v in path[u]:
                if not vis[v]:
                    stk.append(v)
        
        cnt = 0
        for i in range(n + 1):
            if vis[i]:
                if control[i] != -1:
                    cnt += 1
                elif i > 1 and len(path[i]) == 1:
                    cnt = -1
                    break
        
        outs.append(cnt)

    print('\n'.join(map(str, outs)))