# Submission link: https://codeforces.com/contest/729/submission/281547787
def main():
    n, s = MII()
    s -= 1
    nums = LII()

    ans = 0
    cnt = [0] * n

    for i in range(n):
        if i == s:
            if nums[i]: ans += 1
        else: cnt[nums[i]] += 1

    cur = 0
    for i in range(1, n):
        if cnt[i]:
            cur += cnt[i]
        else:
            cur += 1
            ans += 1
        if cur >= n - 1: break

    print(ans)