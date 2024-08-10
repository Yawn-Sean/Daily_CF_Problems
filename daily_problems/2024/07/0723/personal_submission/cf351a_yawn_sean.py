# Submission Link: https://codeforces.com/contest/351/submission/271997321
def main():
    n = II()
    nums = [int(s.split('.')[1]) for s in LI()]

    tot = sum(nums)
    cnt = nums.count(0)

    ans = 2000 * n
    for i in range(max(n - cnt, 0), min(2 * n - cnt, n) + 1):
        ans = min(ans, abs(i * 1000 - tot))

    print(ans // 1000, '.', str(ans % 1000).zfill(3), sep='')