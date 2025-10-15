# Submission link: https://codeforces.com/contest/163/submission/331732141
def main():
    s1 = [ord(c) for c in I()]
    s2 = [ord(c) for c in I()]
    
    n1 = len(s1)
    n2 = len(s2)
    
    dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]
    
    mod = 10 ** 9 + 7
    ans = 0
    
    for i in range(n1):
        dp[i][0] = 1
        
        for j in range(n2):
            dp[i][j + 1] += dp[i][j]
            if dp[i][j + 1] >= mod:
                dp[i][j + 1] -= mod
            
            if s1[i] == s2[j]:
                dp[i + 1][j + 1] += dp[i][j]
                if dp[i + 1][j + 1] >= mod:
                    dp[i + 1][j + 1] -= mod
                
                ans += dp[i][j]
                if ans >= mod:
                    ans -= mod
    
    print(ans)