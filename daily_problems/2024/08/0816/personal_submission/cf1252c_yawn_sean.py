# Submission link: https://codeforces.com/contest/1252/submission/276720715
def main():
    n, q = MII()
    nums1 = LII()
    nums2 = LII()
    
    p1 = list(range(n))
    for i in range(1, n):
        if nums1[i] % 2 == nums1[i-1] % 2:
            p1[i] = p1[i-1]
    
    p2 = list(range(n))
    for i in range(1, n):
        if nums2[i] % 2 == nums2[i-1] % 2:
            p2[i] = p2[i-1]
    
    outs = []
    for _ in range(q):
        x1, y1, x2, y2 = GMI()
        outs.append('YES' if p1[x1] == p1[x2] and p2[y1] == p2[y2] else 'NO')
    
    print('\n'.join(outs))