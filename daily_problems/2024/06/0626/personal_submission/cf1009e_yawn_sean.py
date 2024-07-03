# Submission Link: https://codeforces.com/contest/1009/submission/267443349
def main():
    n = II()
    nums = LII()

    mod = 998244353
    pow2 = [1] * (n + 1)
    for i in range(n):
        pow2[i+1] = pow2[i] * 2 % mod

    ans = 0
    for i in range(n):
        ans += nums[i] * (pow2[n - i - 1] + (n - i - 1) * pow2[n - i - 2]) % mod
        ans %= mod

    print(ans)