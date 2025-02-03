# Submission link: https://codeforces.com/contest/457/submission/304196813
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    nums1.sort()
    nums2.sort()

    v1 = sum(nums1)
    v2 = sum(nums2)

    ans = inf

    cur = 0
    for i in range(n):
        ans = fmin(ans, v2 * (n - i) + cur)
        cur += nums1[i]

    cur = 0
    for i in range(m):
        ans = fmin(ans, v1 * (m - i) + cur)
        cur += nums2[i]

    print(ans)