# Submission link: https://codeforces.com/contest/595/submission/310642845
def main():
    n, k = MII()

    nums1 = LII()
    nums2 = LII()

    ans = 1
    mod = 10 ** 9 + 7

    up = 10 ** k - 1
    base = 10 ** (k - 1)

    def f(x, y):
        return x // y + 1

    for i in range(n // k):
        ans = ans * (f(up, nums1[i]) - (f(base * (nums2[i] + 1) - 1, nums1[i]) - f(base * nums2[i] - 1, nums1[i]))) % mod

    print(ans)