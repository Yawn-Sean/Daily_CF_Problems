# Submission link: https://codeforces.com/contest/846/submission/299963456
def main():
    n, k, m = MII()
    time = LII()

    time.sort()
    for i in range(1, k):
        time[i] += time[i - 1]

    inf = 10 ** 18
    dp = [inf] * (n * (k + 1) + 1)

    dp[0] = 0

    for _ in range(n):
        for i in range(n * (k + 1), -1, -1):
            for j in range(k - 1):
                if i - j - 1 >= 0:
                    dp[i] = fmin(dp[i], dp[i - j - 1] + time[j])
            if i >= k + 1:
                dp[i] = fmin(dp[i], dp[i - k - 1] + time[k - 1])

    for i in range(n * (k + 1), -1, -1):
        if dp[i] <= m:
            print(i)
            break