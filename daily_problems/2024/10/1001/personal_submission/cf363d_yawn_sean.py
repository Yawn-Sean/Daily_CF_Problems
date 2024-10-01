# Submission link: https://codeforces.com/contest/363/submission/283833481
def main():
    n, m, a = MII()
    nums1 = LII()
    nums2 = LII()

    nums1.sort()
    nums2.sort()

    l, r = 0, min(n, m)
    while l <= r:
        mid = (l + r) // 2
        cur = 0
        for i in range(mid):
            cur += fmax(nums2[i] - nums1[n - mid + i], 0)
            if cur > a:
                r = mid - 1
                break
        else:
            l = mid + 1

    print(r, fmax(0, sum(nums2[:r]) - a))