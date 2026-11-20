# Submission link: https://codeforces.com/gym/106249/submission/399216374
def main(): 
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n, k, q = MII()
        updates = [[] for _ in range(n + 1)]
        
        for _ in range(q):
            d, l, r, c = MII()
            updates[l - 1].append((1, d, c))
            updates[r].append((-1, d, c))
        
        trie01 = [[-1] * (q * k + 1) for _ in range(2)]
        sz = [0] * (q * k + 1)
        dp = [0] * (q * k + 1)
        
        ans = 0
        pt = 1
        
        for i in range(n):
            for op, d, c in updates[i]:
                cur = 0
                stk = []
                
                for bit in range(k - 1, -1, -1):
                    w = d >> bit & 1
                    stk.append(cur)
                    
                    if trie01[w][cur] == -1:
                        trie01[w][cur] = pt
                        pt += 1
                    
                    cur = trie01[w][cur]
                    sz[cur] += op
                
                dp[cur] += c * op
                
                for cur in reversed(stk):
                    v0 = trie01[0][cur]
                    v1 = trie01[1][cur]
                    
                    f0 = v0 >= 0 and sz[v0] > 0
                    f1 = v1 >= 0 and sz[v1] > 0
                    
                    if f0:
                        if f1: dp[cur] = (dp[v0] + dp[v1]) % mod
                        else: dp[cur] = dp[v0] * 2 % mod
                    else:
                        if f1: dp[cur] = dp[v1] * 2 % mod
                        else: dp[cur] = 0
                
            ans += dp[0]
            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))