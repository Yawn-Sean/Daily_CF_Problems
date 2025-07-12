# Submission link: https://codeforces.com/contest/305/submission/328595692
def main():
    n = II()
    nums = LII()

    cur = 0
    cnt = 0
    total = 0

    for v in nums:
        while cur < v and cnt:
            total += cnt % 2
            cur += 1
            cnt //= 2
        cur = v
        cnt += 1

    while cnt:
        total += cnt % 2
        cur += 1
        cnt //= 2

    print(cur - total)