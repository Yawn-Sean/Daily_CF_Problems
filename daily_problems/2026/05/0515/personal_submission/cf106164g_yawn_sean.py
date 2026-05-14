# Submission link: https://codeforces.com/gym/106164/submission/374451887
def main():  
    n = II()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    pts = [[] for _ in range(3)]
    
    for _ in range(n):
        pt = LII()
        
        for i in range(3):
            pts[i].append(pt[i])
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for msk in path[u]:
            v = msk % n
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    ans = 0
    
    ma = [[0] * n for _ in range(8)]
    
    for i in reversed(que):
        for j in range(8):
            for k in range(3):
                if j >> k & 1:
                    ma[j][i] += pts[k][i]
                else:
                    ma[j][i] -= pts[k][i]
        
        for msk in path[i]:
            w, v = divmod(msk, n)
            if parent[v] == i:
                for j in range(8):
                    ans = fmax(ans, ma[j][v] + w + ma[7 - j][i])
                for j in range(8):
                    ma[j][i] = fmax(ma[j][i], ma[j][v] + w)
    
    print(ans)