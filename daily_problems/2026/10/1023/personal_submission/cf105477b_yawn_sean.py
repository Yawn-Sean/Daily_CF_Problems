# Submission link: https://codeforces.com/gym/105477/submission/395584626
def main():
    mod = 1000000007
    saved = [[0] * 201 for _ in range(201)]
    
    for mx_val in range(1, 201):
        dp = [0] * (mx_val + 1)
        dp[0] = 1
        
        for i in range(400):
            ndp = [0] * (mx_val + 1)
            
            for j in range(mx_val + 1):
                if j: ndp[j] += dp[j - 1]
                if j < mx_val: ndp[j] += dp[j + 1]
                ndp[j] %= mod
            
            dp = ndp
            if i % 2: saved[mx_val][(i + 1) // 2] = dp[0]
    
    for i in range(200, 0, -1):
        for j in range(201):
            saved[i][j] -= saved[i - 1][j]
            saved[i][j] %= mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        l, h = MII()
        outs.append(saved[h][l])
    
    print('\n'.join(map(str, outs)))