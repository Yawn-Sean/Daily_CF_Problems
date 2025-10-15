# Submission link: https://codeforces.com/contest/364/submission/293740080
def main():
    target = II()
    nums = [int(x) for x in I()]
    n = len(nums)

    cnt = [0] * (9 * n + 1)

    for i in range(n):
        cur = 0
        for j in range(i, n):
            cur += nums[j]
            cnt[cur] += 1

    if target == 0:
        total = (n * (n + 1) // 2) ** 2
        total -= (n * (n + 1) // 2 - cnt[0]) ** 2
        print(total)
        exit()

    ans = 0
    for i in range(1, 9 * n + 1):
        if target % i == 0 and target // i <= 9 * n:
            ans += cnt[i] * cnt[target // i]

    print(ans)