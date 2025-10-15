# Submission link: https://codeforces.com/contest/639/submission/295324521
def main():
    n, k = MII()
    nums = LII()

    vals = [0] * (n + 1)
    for i in range(n):
        x, vals[i] = divmod(nums[i] + vals[i], 2)
        vals[i + 1] += x
    vals[n] += nums[n]

    idx = -1
    for i in range(n + 1):
        if vals[i] != 0:
            idx = i
            break

    cur = 0
    ans = 0

    for i in range(n, -1, -1):
        cur = cur * 2 + vals[i]
        if abs(cur) > 2 * k: break
        if i <= idx and abs(nums[i] - cur) <= k and not (i == n and nums[i] == cur):
            ans += 1

    print(ans)