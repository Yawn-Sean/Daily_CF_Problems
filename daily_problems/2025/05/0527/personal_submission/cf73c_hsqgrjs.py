import sys


read = lambda  : sys.stdin.readline().strip()

def solve() :

    s, k = read().split()
    s = ' ' + s
    k = int(k)

    n = int(read())
    L = len(s)
    M = {}
    for i in range(n) :
        x, y, c = read().split()
        c = int(c)
        M[x + y] = c

    dp = [[[-10**9] * L for i in range(k + 1)] for j in range(26)]
    ans = -10**9
    for i in range(26) :
        dp[i][0][0] = 0
    for i in range(1, L) :
        c = ord(s[i]) - ord('a')
        for c2 in range(26) :
            if i > 1 :
                dp[c][0][i] = max(dp[c2][0][i - 1] + M.get(chr(c2 + ord('a')) + chr(c + ord('a')), 0), dp[c][0][i])
            else :
                dp[c][0][i] = 0
            if ans < dp[c][0][i] and i == L - 1:
                ans = dp[c][0][i]
        
        for k1 in range(1, k + 1):
            c1 = ord(s[i]) - ord('a')
            for c2 in range(26) :
                if i > 1 :
                    dp[c1][k1][i] = max(dp[c2][k1][i - 1] + M.get(chr(c2 + ord('a')) + chr(c1 + ord('a')), 0), dp[c1][k1][i])
                else :
                    dp[c1][k1][i] = 0
                if ans < dp[c1][k1][i] and i == L - 1:
                    ans = dp[c1][k1][i]
            
            for c in range(26) :
                for c2 in range(26) :
                    if i > 1 :
                        dp[c][k1][i] = max(dp[c][k1][i], dp[c2][k1 - 1][i - 1] + M.get(chr(c2 + ord('a')) + chr(c + ord('a')), 0))
                    else :
                        dp[c][k1][i] = 0
                    if ans < dp[c][k1][i] and i == L - 1:
                        ans = dp[c][k1][i]

    print(ans)




if __name__ == '__main__' :

    solve()
