# Submission link: https://codeforces.com/problemset/submission/269/317795123
def main():
    n, m = MII()
    vals = []

    for _ in range(n):
        a, b = LI()
        vals.append(int(a))

    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if vals[j] <= vals[i]:
                dp[i] = fmax(dp[i], dp[j] + 1)

    print(n - max(dp))