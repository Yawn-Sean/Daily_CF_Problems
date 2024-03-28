def main():
    n = II()
    nums = LII()

    if 1 in nums:
        print(n - nums.count(1))
        return

    ans = n
    for i in range(n):
        g = nums[i]
        for j in range(i, n):
            g = math.gcd(g, nums[j])
            if g == 1:
                ans = min(ans, j - i)
                break

    print(ans + n - 1 if ans < n else -1)
