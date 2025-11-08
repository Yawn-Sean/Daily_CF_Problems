# Submission link: https://codeforces.com/gym/106170/submission/347863147
def main(): 
    n = II()
    us = []
    vs = []
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = MII()
        us.append(u)
        vs.append(v)
        path[u].append(v)
        path[v].append(u)
    
    def dis(start):
        ans = [-1] * n
        ans[start] = 0
        
        que = [start]
        for u in que:
            for v in path[u]:
                if ans[v] == -1:
                    ans[v] = ans[u] + 1
                    que.append(v)
        
        return ans
    
    d = dis(0)
    diameter_u = d.index(max(d))
    d1 = dis(diameter_u)
    diameter_v = d1.index(max(d1))
    d2 = dis(d1.index(max(d1)))
    
    ans = n
    chosen = -1
    
    for i in range(n):
        if len(path[i]) == 1:
            v = fmax(d1[i], d2[i])
            if v < ans:
                ans = v
                chosen = i
    
    outs = []
    outs.append(str(ans))
    
    cur = [diameter_v]
    while cur[-1] != diameter_u:
        for v in path[cur[-1]]:
            if d1[cur[-1]] - d1[v] == 1:
                cur.append(v)
                break
    
    k = len(cur)
    
    notes = [-1] * n
    idx = cur[k // 2]
    notes[idx] = k // 2
    
    parent = [-1] * n
    
    que = [idx]
    
    for u in que:
        for v in path[u]:
            if notes[v] == -1:
                if d1[v] >= d2[v]: notes[v] = notes[u] - 1
                else: notes[v] = notes[u] + 1
                parent[v] = u
                que.append(v)
    
    find_leaf = list(range(n))
    
    for u in reversed(que):
        if parent[u] != -1:
            find_leaf[parent[u]] = find_leaf[u]
    
    for i in range(n - 1):
        u, v = us[i], vs[i]
        if notes[u] > notes[v]:
            u, v = v, u
        
        leaf = find_leaf[u] if d1[u] >= d2[u] else find_leaf[v]
        end = cur[notes[leaf] - ans] if notes[leaf] >= ans else cur[notes[leaf] + ans]
        outs.append(f'{notes[u] % ans} {leaf} {end}')
    
    print('\n'.join(outs))