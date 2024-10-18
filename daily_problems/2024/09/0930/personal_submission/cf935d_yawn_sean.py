# Submission link: https://codeforces.com/contest/935/submission/283686697
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    ans = 0
    prob = 1
    mod = 10 ** 9 + 7

    inv2 = pow(2, -1, mod)
    invm = pow(m, -1, mod)

    for i in range(n):
        if nums1[i]:
            if nums2[i]:
                if nums1[i] > nums2[i]:
                    ans += prob
                    if ans >= mod:
                        ans -= mod
                    break
                elif nums1[i] < nums2[i]:
                    break
            else:
                ans += prob * (nums1[i] - 1) % mod * invm % mod
                if ans >= mod:
                    ans -= mod
                prob = prob * invm % mod
        else:
            if nums2[i]:
                ans += prob * (m - nums2[i]) % mod * invm % mod
                if ans >= mod:
                    ans -= mod
                prob = prob * invm % mod
            else:
                ans += prob * (m - 1) % mod * inv2 % mod * invm % mod
                if ans >= mod:
                    ans -= mod
                prob = prob * invm % mod

    print(ans)