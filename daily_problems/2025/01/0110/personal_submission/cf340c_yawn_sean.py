# Submission link: https://codeforces.com/contest/340/submission/300336846
def main():
    n = II()
    nums = LII()

    nums.sort()
    ans = 0

    for i in range(n):
        ans += (4 * i - 2 * n + 3) * nums[i]

    g = math.gcd(ans, n)
    print(ans // g, n // g)