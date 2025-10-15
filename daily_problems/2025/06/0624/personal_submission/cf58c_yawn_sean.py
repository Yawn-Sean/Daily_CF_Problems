# Submission link: https://codeforces.com/contest/58/submission/325846481
def main():
    n = II()
    nums = LII()

    cnt = [0] * (10 ** 5 + 1)

    for i in range(n):
        x = nums[i] - fmin(i, n - 1 - i)
        if x > 0:
            cnt[x] += 1

    print(n - max(cnt))