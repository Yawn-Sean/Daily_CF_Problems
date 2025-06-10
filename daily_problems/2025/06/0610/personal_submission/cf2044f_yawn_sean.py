# Submission link: https://codeforces.com/contest/2044/submission/323696072
def main():
    n, m, q = MII()
    nums1 = LII()
    nums2 = LII()

    bound = 2 * 10 ** 5
    v1 = [0] * (bound * 2 + 1)
    v2 = [0] * (bound * 2 + 1)

    val1 = sum(nums1)
    val2 = sum(nums2)

    for v in nums1:
        x = val1 - v
        if -bound <= x <= bound:
            v1[bound + x] = 1

    for v in nums2:
        x = val2 - v
        if -bound <= x <= bound:
            v2[bound + x] = 1

    outs = []

    for _ in range(q):
        x = II()
        flg = False
        for i in range(1, 501):
            if x % i == 0:
                j = x // i
                if v1[i + bound] and v2[j + bound]: flg = True
                if v2[i + bound] and v1[j + bound]: flg = True
                if v1[-i + bound] and v2[-j + bound]: flg = True
                if v2[-i + bound] and v1[-j + bound]: flg = True
                if flg: break
        
        if flg: outs.append('YES')
        else: outs.append('NO')

    print('\n'.join(outs))