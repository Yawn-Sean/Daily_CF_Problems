# Submission link: https://codeforces.com/gym/106368/submission/399015286
def main():
    n = II()
    
    strs1 = LI()
    strs2 = LI()
    
    pos1 = [[] for _ in range(26)]
    pos2 = [[] for _ in range(26)]
    
    ans = 0
    
    for i in range(n):
        s1 = [ord(x) - ord('a') for x in strs1[i]]
        s2 = [ord(x) - ord('a') for x in strs2[i]]
        
        k1 = len(s1)
        k2 = len(s2)
        
        for j in range(k1):
            pos1[s1[j]].append(i)
        
        for j in range(k2):
            pos2[s2[j]].append(i)
        
        dp = [[0] * (k2 + 1) for _ in range(k1 + 1)]
        
        for i in range(k1):
            for j in range(k2):
                if s1[i] == s2[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = fmax(dp[i][j + 1], dp[i + 1][j])
        
        ans -= dp[k1][k2]
    
    for i in range(26):
        if len(pos1[i]) != len(pos2[i]): exit(print(-1))
        else:
            for x, y in zip(pos1[i], pos2[i]):
                ans += abs(x - y) + 1
    
    print(ans)