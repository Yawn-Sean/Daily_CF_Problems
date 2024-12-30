# Submission link: https://codeforces.com/contest/433/submission/281547087
def main():
    n, m = MII()
    nums = LII()

    cur = [0] * (n + 1)
    tmp = [[] for _ in range(n + 1)]

    orig = 0
    for i in range(1, m):
        v = abs(nums[i] - nums[i - 1])
        orig += v

        if nums[i] != nums[i-1]:
            cur[nums[i]] += v
            cur[nums[i-1]] += v
            tmp[nums[i]].append(nums[i-1])
            tmp[nums[i-1]].append(nums[i])

    res = 0
    for i in range(1, n + 1):
        if len(tmp[i]):
            tmp[i].sort()
            x = tmp[i][len(tmp[i]) // 2]
            res = max(res, cur[i] - sum(abs(x - v) for v in tmp[i]))

    print(orig - res)