# Submission link: https://codeforces.com/contest/1238/submission/334793018
def main():
    t = II()
    inf = 10 ** 6
    outs = []
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        parent = [-1] * n
        que = [0]
        
        for u in que:
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    que.append(v)
        
        ans = 0
        dp = [0] * n
        
        for u in reversed(que):
            x1, x2 = -inf, -inf
            for v in path[u]:
                if parent[v] == u:
                    if dp[v] > x1:
                        x1, x2 = dp[v], x1
                    elif dp[v] > x2:
                        x2 = dp[v]
            
            sons_count = len(path[u])
            if u > 0: sons_count -= 1
            
            dp[u] = fmax(1, x1 + 1 + (sons_count - 1))
            ans = fmax(ans, dp[u])
            ans = fmax(ans, x1 + x2 + 1 + (len(path[u]) - 2))
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))