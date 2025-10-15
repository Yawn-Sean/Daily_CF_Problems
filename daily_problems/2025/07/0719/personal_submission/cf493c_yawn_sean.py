# Submission link: https://codeforces.com/contest/493/submission/329636306
def main():
    n = II()
    nums1 = LII()
    m = II()
    nums2 = LII()

    nums1.sort()
    nums2.sort()

    inf = 10 ** 9 * 2 + 10

    p1, p2 = 0, 0
    ans1, ans2 = 3 * n, 3 * m

    while p1 < n or p2 < m:
        cur = inf
        if p1 < n: cur = fmin(cur, nums1[p1])
        if p2 < m: cur = fmin(cur, nums2[p2])
        
        while p1 < n and nums1[p1] == cur:
            p1 += 1
        
        while p2 < m and nums2[p2] == cur:
            p2 += 1
        
        v1 = 2 * p1 + 3 * (n - p1)
        v2 = 2 * p2 + 3 * (m - p2)
        
        if v1 - v2 > ans1 - ans2:
            ans1, ans2 = v1, v2

    print(f'{ans1}:{ans2}')