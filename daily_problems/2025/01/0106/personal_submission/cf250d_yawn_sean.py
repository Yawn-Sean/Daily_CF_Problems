# Submission link: https://codeforces.com/contest/250/submission/299835021
def main():
    n, m, a, b = MII()
    nums1 = LII()
    nums2 = LII()
    nums3 = LII()

    def dis(i, j):
        return (a * a + nums1[i] * nums1[i]) ** 0.5 + ((b - a) * (b - a) + (nums2[j] - nums1[i]) * (nums2[j] - nums1[i])) ** 0.5 + nums3[j]

    ans = 10 ** 9
    idx1, idx2 = -1, -1
    pt = 0

    for i in range(m):
        while pt < n - 1 and dis(pt, i) > dis(pt + 1, i):
            pt += 1
        
        nans = dis(pt, i)
        if nans < ans:
            ans = nans
            idx1, idx2 = pt, i

    print(idx1 + 1, idx2 + 1)