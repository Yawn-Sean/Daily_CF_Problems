# Submission link: https://codeforces.com/contest/1065/submission/281054639
def main():
    mod = 998244353

    n, m, a = MII()
    nums = LII()

    ans = 1
    cur = 0
    for num in nums:
        v = pow(a, num - cur, mod)
        ans *= v * (v + 1) // 2 % mod
        ans %= mod
        cur = num

    print(ans * pow(a, n - nums[-1] * 2, mod) % mod)