# Submission link: https://codeforces.com/contest/18/submission/331603791
def main():
    last = [-1] * 2005
    n = II()

    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        s, x = LI()
        x = int(x)
        
        dp[i] = dp[i - 1]
        
        if s[0] == 'w':
            last[x] = i - 1
        else:
            if last[x] != -1:
                dp[i] = fmax(dp[i], dp[last[x]] + (1 << x))

    print(dp[n])