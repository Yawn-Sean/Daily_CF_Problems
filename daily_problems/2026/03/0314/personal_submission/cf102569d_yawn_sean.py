# Submission link: https://codeforces.com/gym/102569/submission/366478507
def main(): 
    n, m = MII()
    us = []
    vs = []
    chs = []
    
    path = [[] for _ in range(n)]
    
    for i in range(m):
        u, v, ch = LI()
        u = int(u) - 1
        v = int(v) - 1
        path[u].append(i)
        path[v].append(i)
        us.append(u)
        vs.append(v)
        chs.append(ord(ch))
    
    dis = [-1] * n
    que = [n - 1]
    dis[n - 1] = 0
    
    for u in que:
        for eid in path[u]:
            v = us[eid] ^ vs[eid] ^ u
            if dis[v] == -1:
                dis[v] = dis[u] + 1
                que.append(v)
    
    parent = [-1] * n
    
    s = []
    cur = [0]
    
    while cur[0] != n - 1:
        min_ch = 128
        for u in cur:
            for eid in path[u]:
                v = us[eid] ^ vs[eid] ^ u
                if dis[v] == dis[u] - 1:
                    min_ch = fmin(min_ch, chs[eid])
        
        s.append(min_ch)
        
        ncur = []
        for u in cur:
            for eid in path[u]:
                v = us[eid] ^ vs[eid] ^ u
                if dis[v] == dis[u] - 1 and chs[eid] == min_ch and parent[v] == -1:
                    ncur.append(v)
                    parent[v] = u
        
        cur = ncur
    
    print(len(s))
    
    ans = [n - 1]
    while ans[-1] != 0:
        ans.append(parent[ans[-1]])
    
    ans.reverse()
    print(' '.join(str(x + 1) for x in ans))
    
    print(''.join(chr(c) for c in s))