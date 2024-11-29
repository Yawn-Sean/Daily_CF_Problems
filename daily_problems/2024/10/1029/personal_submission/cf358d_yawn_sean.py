# Submission link: https://codeforces.com/contest/358/submission/288651177
def main():
    n = II()
    nums0 = LII()
    nums1 = LII()
    nums2 = LII()

    dp0, dp1 = nums0[0], nums1[0]

    for i in range(1, n):
        dp0, dp1 = fmax(dp0 + nums1[i], dp1 + nums0[i]), fmax(dp0 + nums2[i], dp1 + nums1[i])

    print(dp0)