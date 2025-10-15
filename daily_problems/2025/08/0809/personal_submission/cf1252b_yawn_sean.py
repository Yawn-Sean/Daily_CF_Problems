# Submission link: https://codeforces.com/contest/1252/submission/333026052
def main():
    n = II()
    mod = 10 ** 9 + 7
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    que = [0]
    parent = [-1] * n
    
    for u in que:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    dp0 = [0] * n
    dp1 = [0] * n
    dp2 = [0] * n
    
    for u in reversed(que):
        v1, v2, v3 = 0, 0, 1
        s1, s2 = 0, 1
        
        for v in path[u]:
            if parent[v] == u:
                v1 = (v1 * dp2[v] + v2 * dp1[v]) % mod
                v2 = (v2 * dp2[v] + v3 * dp1[v]) % mod
                v3 = v3 * dp2[v] % mod
                
                s1 = (s1 * dp0[v] + s2 * dp1[v]) % mod
                s2 = s2 * dp0[v] % mod
        
        dp0[u] = v1
        dp1[u] = (v2 + s2) % mod
        dp2[u] = (dp0[u] + s1 + s2) % mod
    
    print(dp2[0])