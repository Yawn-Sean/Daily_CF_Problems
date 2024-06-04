# Submission link: https://codeforces.com/contest/609/submission/263076675
def main():
    n, m, k, s = MII()
    nums1 = LII()
    nums2 = LII()

    idxs1 = list(range(n))
    idxs2 = list(range(n))

    for i in range(1, n):
        if nums1[i] > nums1[i-1]:
            nums1[i] = nums1[i-1]
            idxs1[i] = idxs1[i-1]
        if nums2[i] > nums2[i-1]:
            nums2[i] = nums2[i-1]
            idxs2[i] = idxs2[i-1]

    ts = []
    cs = []

    for i in range(m):
        t, c = MII()
        ts.append(t)
        cs.append(c)

    c1 = [cs[i] for i in range(m) if ts[i] == 1]
    c2 = [cs[i] for i in range(m) if ts[i] == 2]
    c1.sort()
    c2.sort()

    l, r = 1, n
    while l <= r:
        mid = (l + r) // 2
        pt1 = pt2 = 0
        tot = 0    
        
        for _ in range(k):
            if pt1 == len(c1):
                tot += c2[pt2] * nums2[mid - 1]
                pt2 += 1
            elif pt2 == len(c2):
                tot += c1[pt1] * nums1[mid - 1]
                pt1 += 1
            elif c1[pt1] * nums1[mid - 1] < c2[pt2] * nums2[mid - 1]:
                tot += c1[pt1] * nums1[mid - 1]
                pt1 += 1
            else:
                tot += c2[pt2] * nums2[mid - 1]
                pt2 += 1
        
        if tot <= s:
            r = mid - 1
        else:
            l = mid + 1

    if l == n + 1:
        print(-1)
    else:
        print(l)
        buy1 = idxs1[l - 1]
        buy2 = idxs2[l - 1]
        cur = []
        for i in range(m):
            if ts[i] == 1: cur.append(nums1[l - 1] * cs[i] * m + i)
            else: cur.append(nums2[l - 1] * cs[i] * m + i)
        chosen = nsmallest(k, cur)
        ans = []
        for x in chosen:
            idx = x % m
            if ts[idx] == 1: ans.append(f'{idx + 1} {buy1 + 1}')
            else: ans.append(f'{idx + 1} {buy2 + 1}')
        print('\n'.join(ans))