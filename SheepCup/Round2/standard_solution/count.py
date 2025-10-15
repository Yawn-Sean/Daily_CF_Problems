def main():
    t = II()
    outs = []

    mod = 10 ** 9 + 7
    pw2 = [1] * (10 ** 5 + 1)

    for i in range(10 ** 5):
        pw2[i + 1] = pw2[i] * 2 % mod

    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        order = []
        parent = [-1] * n
        
        stk = [0]
        while stk:
            u = stk.pop()
            order.append(u)
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    stk.append(v)
        
        order.reverse()
        
        ans = n - 1
        
        for i in range(n):
            if len(path[i]) > 1:
                ans += pw2[len(path[i])] - len(path[i]) - 1
                ans %= mod
        
        dp = [0] * n
        for i in order:
            cur_sum = 0
            for j in path[i]:
                if parent[j] == i:
                    ans += (dp[j] + pw2[len(path[j]) - 1] - 1) * (pw2[len(path[i]) - 1] - 1) % mod
                    ans %= mod
                    
                    if cur_sum:
                        ans += cur_sum * (dp[j] + pw2[len(path[j]) - 1] - 1) % mod * pw2[len(path[i]) - 2] % mod
                        ans %= mod
                    cur_sum += dp[j] + pw2[len(path[j]) - 1] - 1
                    cur_sum %= mod
            
            d = len(path[i]) - 1
            if i != 0: d -= 1
            
            for j in path[i]:
                if parent[j] == i:
                    dp[i] += (dp[j] + pw2[len(path[j]) - 1] - 1) * pw2[d] % mod
                    dp[i] %= mod
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))