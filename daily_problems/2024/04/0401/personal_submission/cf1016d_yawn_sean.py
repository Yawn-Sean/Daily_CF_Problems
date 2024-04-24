def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()
    
    if reduce(xor, nums1) != reduce(xor, nums2):
        exit(print('NO'))
    
    ans = [[0] * m for _ in range(n)]
    v = nums1[0]
    for i in range(1, m):
        ans[0][i] = nums2[i]
        v ^= nums2[i]
    
    ans[0][0] = v
    
    for i in range(1, n):
        ans[i][0] = nums1[i]
    
    print('YES')
    print('\n'.join(' '.join(map(str, x)) for x in ans))
