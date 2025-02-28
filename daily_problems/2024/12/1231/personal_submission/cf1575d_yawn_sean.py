# Submission link: https://codeforces.com/contest/1575/submission/299120108
def main():
    s = I()
    n = len(s)

    if n == 1:
        print(1 if s == '0' or s == '_' or s == 'X' else 0)

    else:
        ans = 0
        for x in (range(10) if 'X' in s else [0]):
            dp = [0] * 25
            ndp = [0] * 25
            dp[0] = 1
            
            for i in range(n):
                if s[i] != '_':
                    d = int(s[i]) if s[i] != 'X' else x
                    if not (i == 0 and d == 0):
                        for mod in range(25):
                            ndp[(mod * 10 + d) % 25] += dp[mod]
                else:
                    for d in range(10):
                        if i == 0 and d == 0:
                            continue
                        for mod in range(25):
                            ndp[(mod * 10 + d) % 25] += dp[mod]
                
                for mod in range(25):
                    dp[mod] = ndp[mod]
                    ndp[mod] = 0
            
            ans += dp[0]
        
        print(ans)