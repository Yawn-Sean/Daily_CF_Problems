# Submission link: https://codeforces.com/contest/1210/submission/282845675
def main():
    n = II()
    nums1 = LII()
    nums2 = LII()

    cnt = Counter(nums1)
    used = [0] * n

    ans = 0
    for x in cnt:
        if cnt[x] > 1:
            for i in range(n):
                if not used[i] and nums1[i] & x == nums1[i]:
                    used[i] = 1
                    ans += nums2[i]

    print(ans)