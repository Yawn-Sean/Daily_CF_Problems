# Submission link: https://codeforces.com/contest/439/submission/255937070
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    nums1.sort()
    nums2.sort(reverse=True)

    print(sum(max(0, y - x) for x, y in zip(nums1, nums2)))