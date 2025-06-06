# Submission link: https://codeforces.com/problemset/submission/272/314945023
def main():
    n = II()
    nums1 = LII()
    nums2 = LII()
    mod = II()

    cnt = Counter()
    rnd = random.getrandbits(30)

    for x in nums1:
        cnt[x ^ rnd] += 1

    for x in nums2:
        cnt[x ^ rnd] += 1

    to_divide = 0
    for i in range(n):
        if nums1[i] == nums2[i]:
            to_divide += 1

    ans = 1
    for x in cnt.values():
        for y in range(1, x + 1):
            while to_divide and y % 2 == 0:
                to_divide -= 1
                y //= 2
            ans = ans * y % mod

    print(ans)