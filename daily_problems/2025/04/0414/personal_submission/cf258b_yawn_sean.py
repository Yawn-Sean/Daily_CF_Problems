# Submission link: https://codeforces.com/problemset/submission/258/315516664
def main():
    m = II()
    m += 1

    vals = []
    while m:
        vals.append(m % 10)
        m //= 10

    vals.reverse()

    dp = [0] * 10
    cnt = 0

    for x in vals:
        for i in range(9, 0, -1):
            dp[i] = dp[i] * 8 + dp[i - 1] * 2
        dp[0] = dp[0] * 8
        
        for i in range(x):
            dp[cnt + (i == 4 or i == 7)] += 1
        
        cnt += (x == 4 or x == 7)

    dp[0] -= 1

    mod = 10 ** 9 + 7

    def f(i, total):
        if total > 9: return 0
        if i < 6:
            ans = 0
            for j in range(10):
                if dp[j]:
                    dp[j] -= 1
                    ans += (dp[j] + 1) * f(i + 1, total + j)
                    dp[j] += 1
            return ans % mod
        else:
            ans = 0
            for j in range(total + 1, 10):
                ans += dp[j]
            return ans

    print(f(0, 0))