# Submission link: https://codeforces.com/gym/105874/submission/353559581
def main(): 
    M = 2 * 10 ** 5
    mod = 998244353
    
    f = Factorial(M * 2, mod)
    
    saved_dp = [[0] * (M + 1) for _ in range(451)]
    
    for i in range(1, 451):
        saved_dp[i][0] = 1
        
        for j in range(1, M + 1):
            saved_dp[i][j] = saved_dp[i][j - 1]
            if j >= i:
                saved_dp[i][j] += saved_dp[i][j - i]
            saved_dp[i][j] %= mod
        
        for j in range(1, M + 1):
            saved_dp[i][j] += saved_dp[i][j - 1]
            saved_dp[i][j] %= mod
    
    n, q = MII()
    outs = []
    
    for _ in range(q):
        l, r, k = MII()
        if k <= 450:
            outs.append((saved_dp[k][r] - saved_dp[k][l - 1]) % mod)
        else:
            ans = 0
            
            for cnt_k in range(r // k + 1):
                lbound = fmax(l - cnt_k * k, 0) - 1
                rbound = r - cnt_k * k
                
                ans += f.combi(rbound + cnt_k + 1, cnt_k + 1) - f.combi(lbound + cnt_k + 1, cnt_k + 1)
                ans %= mod
            
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))