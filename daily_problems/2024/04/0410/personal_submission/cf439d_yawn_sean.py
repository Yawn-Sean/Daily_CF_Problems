# Submission link: https://codeforces.com/contest/439/submission/255936919
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    nums1.sort()
    nums2.sort()

    acc1 = list(accumulate(nums1, initial=0))
    acc2 = list(accumulate(nums2, initial=0))

    ans = inf

    for num in nums1:
        p1 = bisect.bisect(nums1, num)
        p2 = bisect.bisect(nums2, num)
        ans = min(ans, num * p1 - acc1[p1] + acc2[m] - acc2[p2] - num * (m - p2))

    for num in nums2:
        p1 = bisect.bisect(nums1, num)
        p2 = bisect.bisect(nums2, num)
        ans = min(ans, num * p1 - acc1[p1] + acc2[m] - acc2[p2] - num * (m - p2))

    print(ans)