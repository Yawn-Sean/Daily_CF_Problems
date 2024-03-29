def main():
    n = II()
    nums = LII()

    if 1 in nums:
        print(n - nums.count(1))
        return
    ans = inf
    for i in range(n):
        res = nums[i]
        for j in range(i, n):
            res = math.gcd(res, nums[j])
            if res == 1:
                ans = min(ans, j - i)
    ans = ans + n - 1 if ans != inf else -1
    print(ans)
    return
