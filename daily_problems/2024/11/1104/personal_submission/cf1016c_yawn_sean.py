# Submission link: https://codeforces.com/contest/1016/submission/289843172
def main():
    n = II()
    nums1 = LII()
    nums2 = LII()

    acc1 = [0] * (n + 1)
    acc2 = [0] * (n + 1)

    for i in range(n):
        acc1[i + 1] = acc1[i] + nums1[i]
        acc2[i + 1] = acc2[i] + nums2[i]

    dp1 = [0] * (n + 1)
    dp2 = [0] * (n + 1)

    for i in range(n - 1, -1, -1):
        dp1[i] = dp1[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2 * i * nums1[i] + (2 * n - 1) * nums2[i]
        dp2[i] = dp2[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2 * i * nums2[i] + (2 * n - 1) * nums1[i]

    ans = dp1[0]
    cur = 0

    for i in range(n):
        if i % 2:
            cur += 2 * i * nums2[i] + (2 * i + 1) * nums1[i]
            ans = fmax(ans, cur + dp1[i + 1])
        else:
            cur += 2 * i * nums1[i] + (2 * i + 1) * nums2[i]
            ans = fmax(ans, cur + dp2[i + 1])

    print(ans)