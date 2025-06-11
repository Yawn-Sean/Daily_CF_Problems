# Submission Link: https://codeforces.com/contest/1195/submission/269328396
def main():
    n = II()
    nums = LII()

    ans = 0
    cnt = [0] * 11
    mod = 998244353

    for x in nums:
        cnt[len(str(x))] += 1

    for x in nums:
        
        a, b, power = x, 0, 1
        for i in range(1, 11):
            b = (b + a % 10 * power) % mod
            a //= 10
            ans += (a * 10 * power % mod + b) * cnt[i] * 10 % mod
            ans += (a * 100 * power % mod + b) * cnt[i] % mod
            ans %= mod
            power = power * 100 % mod

    print(ans)