# Submission link: https://codeforces.com/contest/457/submission/304198830
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    v1 = sum(nums1)
    v2 = sum(nums2)

    ans1 = 0
    for x in nums1:
        ans1 += fmin(v2, x)
    ans1 += v2 - fmin(max(nums1), v2)

    ans2 = 0
    for x in nums2:
        ans2 += fmin(v1, x)
    ans2 += v1 - fmin(max(nums2), v1)

    print(min(ans1, ans2))