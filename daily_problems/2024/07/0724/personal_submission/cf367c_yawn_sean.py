# Submission Link: https://codeforces.com/contest/367/submission/272226304
def main():
    def f(x):
        return x * (x + 1) // 2 + 1 if x % 2 == 0 else x * (x + 1) // 2 + x // 2 + 1

    n, m = MII()
    nums = []

    for _ in range(m):
        _, x = MII()
        nums.append(x)

    nums.sort(reverse=True)
    ans = 0

    for i in range(m):
        if f(i) > n: break
        ans += nums[i]

    print(ans)