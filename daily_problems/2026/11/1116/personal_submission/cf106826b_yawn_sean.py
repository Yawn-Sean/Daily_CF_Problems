# Submission link: https://codeforces.com/gym/106826/submission/398645041
def main():
    t = II()
    outs = []
    mod = 998244353
    
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
        
        dp = [1] * n
        
        for u in reversed(que):
            tmp = []
            
            for v in path[u]:
                if parent[v] == u:
                    tmp.append(v)
            
            if len(tmp) == 3:
                dp[u] = 0
                continue
            
            elif len(tmp):
                dp[u] = 2
                for v in tmp:
                    dp[u] = dp[u] * dp[v] % mod
        
        rev_dp = [1] * n
        
        for u in que:
            if u == 0:
                if len(path[u]) == 1:
                    rev_dp[path[u][0]] = rev_dp[u]
                
                else:
                    for x in path[0]:
                        rev_dp[x] = 2
                        for y in path[0]:
                            if y != x:
                                rev_dp[x] = rev_dp[x] * dp[y] % mod
            else:
                sons = []
                for v in path[u]:
                    if parent[v] == u:
                        sons.append(v)
                
                for x in sons:
                    rev_dp[x] = 2 * rev_dp[u] % mod
                    for y in sons:
                        if y != x:
                            rev_dp[x] = rev_dp[x] * dp[y] % mod
        
        ans = 0
        for i in range(n):
            if len(path[i]) <= 2:
                res = 2 * rev_dp[i] % mod
                for j in path[i]:
                    if parent[j] == i:
                        res = res * dp[j] % mod
                ans = (ans + res) % mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))