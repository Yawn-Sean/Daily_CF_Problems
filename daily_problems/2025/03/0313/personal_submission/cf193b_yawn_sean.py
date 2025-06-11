# Submission link: https://codeforces.com/contest/193/submission/310330970
def main():
    n, u, r = MII()
    nums1 = LII()
    nums2 = LII()
    ks = LII()
    perm = LGMI()

    ans = -10 ** 18
    def f(nums, op, last):
        global ans
        if (u - op) % 2 == 0:
            ans = fmax(ans, sum(nums[i] * ks[i] for i in range(n)))
        if op == u: return
        f([nums[x] + r for x in perm], op + 1, 0)
        if not last:
            f([nums[x] ^ nums2[x] for x in range(n)], op + 1, 1)

    f(nums1, 0, 0)
    print(ans)