# Submission link: https://codeforces.com/contest/222/submission/307471915
def main():
    prime_factor = list(range(10 ** 7 + 1))
    for i in range(2, 10 ** 7 + 1):
        if prime_factor[i] == i:
            for j in range(i, 10 ** 7 + 1, i):
                prime_factor[j] = i

    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    cnt1 = [0] * (10 ** 7 + 1)
    cnt2 = [0] * (10 ** 7 + 1)

    for x in nums1:
        while x > 1:
            cnt1[prime_factor[x]] += 1
            x //= prime_factor[x]

    for x in nums2:
        while x > 1:
            cnt2[prime_factor[x]] += 1
            x //= prime_factor[x]

    for i in range(10 ** 7 + 1):
        cnt1[i] = fmin(cnt1[i], cnt2[i])
        cnt2[i] = cnt1[i]

    for i in range(n):
        x = nums1[i]
        while x > 1:
            if cnt1[prime_factor[x]]:
                cnt1[prime_factor[x]] -= 1
                nums1[i] //= prime_factor[x]
            x //= prime_factor[x]

    for i in range(m):
        x = nums2[i]
        while x > 1:
            if cnt2[prime_factor[x]]:
                cnt2[prime_factor[x]] -= 1
                nums2[i] //= prime_factor[x]
            x //= prime_factor[x]

    print(n, m)
    print(*nums1)
    print(*nums2)