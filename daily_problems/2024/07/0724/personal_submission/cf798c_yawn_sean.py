# Submission Link: https://codeforces.com/contest/798/submission/272225927
def main():
    n = II()
    nums = LII()

    print('YES')
    if math.gcd(*nums) > 1:
        print(0)
    else:
        ans = 0
        cnt = 0
        for num in nums:
            if num % 2:
                cnt += 1
            else:
                ans += cnt // 2 + cnt % 2 * 2
                cnt = 0
        ans += cnt // 2 + cnt % 2 * 2
        print(ans)