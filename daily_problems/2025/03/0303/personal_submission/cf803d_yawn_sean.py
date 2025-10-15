# Submission link: https://codeforces.com/problemset/submission/803/308724594
def main():
    k = II()
    s = I()

    nums = []

    cnt = 0
    for c in s:
        cnt += 1
        if c == ' ' or c == '-':
            nums.append(cnt)
            cnt = 0

    nums.append(cnt)

    l = max(nums)
    r = 10 ** 6

    while l <= r:
        m = (l + r) // 2
        cnt = 1
        cur = 0
        for x in nums:
            cur += x
            if cur > m:
                cnt += 1
                cur = x
        if cnt > k: l = m + 1
        else: r = m - 1

    print(l)