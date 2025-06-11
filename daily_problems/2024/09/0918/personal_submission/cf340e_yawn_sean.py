# Submission link: https://codeforces.com/contest/340/submission/281675545
def main():
    mod = 10 ** 9 + 7

    n = II()
    nums = LGMI()

    used = [0] * n
    for i in nums:
        if i >= 0:
            used[i] = 1

    x0, x1 = 0, 0
    for i in range(n):
        if not used[i]:
            if nums[i] < 0: x0 += 1
            else: x1 += 1

    fact = Factorial(n, mod)

    ans = 0
    cur = 1
    for i in range(0, x0 + 1):
        ans += cur * fact.fac(x0 + x1 - i) * fact.combi(x0, i)
        cur = -cur
        ans %= mod

    print(ans)
