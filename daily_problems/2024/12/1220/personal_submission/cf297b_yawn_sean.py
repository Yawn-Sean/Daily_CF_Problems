# Submission link: https://codeforces.com/contest/297/submission/297371629
def main():
    n, m, k = MII()
    nums1 = LII()
    nums2 = LII()
    nums1.sort(reverse=True)
    nums2.sort(reverse=True)

    if n > m: print('YES')
    else:
        for i in range(n):
            if nums1[i] > nums2[i]:
                exit(print('YES'))
        
        print('NO')