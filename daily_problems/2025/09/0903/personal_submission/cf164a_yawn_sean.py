# Submission link: https://codeforces.com/contest/164/submission/336615987
def main():
    n, m = MII()
    vals = LII()
    
    path = [[] for _ in range(n)]
    rev_path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        rev_path[v].append(u)
    
    vis1 = [0] * n
    que = []
    
    for i in range(n):
        if vals[i] == 1:
            vis1[i] = 1
            que.append(i)
    
    for u in que:
        for v in path[u]:
            if not vis1[v] and (vals[v] == 0 or vals[v] == 2):
                vis1[v] = 1
                que.append(v)
    
    vis2 = [0] * n
    que = []
    
    for i in range(n):
        if vals[i] == 2:
            vis2[i] = 1
            que.append(i)
    
    for u in que:
        if vals[u] == 1: continue
        
        for v in rev_path[u]:
            if not vis2[v]:
                vis2[v] = 1
                que.append(v)
    
    print('\n'.join(str(vis1[i] & vis2[i]) for i in range(n)))