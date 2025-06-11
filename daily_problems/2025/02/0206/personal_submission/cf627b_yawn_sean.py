# Submission link: https://codeforces.com/contest/627/submission/304632929
def main():
    n, k, a, b, q = MII()

    nums1 = [0] * n
    nums2 = [0] * n

    fen1 = FenwickTree(n)
    fen2 = FenwickTree(n)

    outs = []
    for _ in range(q):
        query = LII()
        if query[0] == 1:
            x = query[1] - 1
            y = query[2]
            
            v = fmin(nums1[x] + y, b) - nums1[x]
            nums1[x] += v
            fen1.add(x, v)
            
            v = fmin(nums2[x] + y, a) - nums2[x]
            nums2[x] += v
            fen2.add(x, v)
        
        else:
            x = query[1] - 1
            outs.append(fen1.sum(x - 1) + fen2.rsum(x + k, n - 1))

    print('\n'.join(map(str, outs)))