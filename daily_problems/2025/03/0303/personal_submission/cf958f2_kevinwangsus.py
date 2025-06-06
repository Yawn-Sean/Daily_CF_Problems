# https://codeforces.com/problemset/problem/958/f2
# https://codeforces.com/contest/958/submission/309578128
def main():
    n, m = MII()
    nums = LGMI()
    cnt = LII()

    # 不定长滑动窗口，越长越合法
    # 求满足not_satisfied == 0的情况下，窗口最小长度
    not_satisfied = sum(1 for c in cnt if c)
    prescribed_cnt = sum(cnt)

    ans = n + 1
    left = 0
    for right in range(n):
        cnt[nums[right]] -= 1
        if cnt[nums[right]] == 0:
            not_satisfied -= 1

        while not_satisfied == 0 and left <= right:
            ans = min(ans, right - left + 1 - prescribed_cnt)
            cnt[nums[left]] += 1
            if cnt[nums[left]] == 1:
                not_satisfied += 1
            left += 1

    print(ans if ans <= n else -1)


if __name__ == "__main__":
    main()
