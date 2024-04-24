def main():
    n = II()
    nums = LII()

    cnt = [0] * (10**5 + 1)
    for num in nums:
        while num:
            cnt[num] += 1
            num //= 2

    maxn = max(cnt)
    for i in range(10**5, -1, -1):
        if cnt[i] == maxn:
            prefix = i
            break

    ans = 0
    for i in range(n):
        v = nums[i] // prefix
        while True:
            v, _ = divmod(nums[i], prefix)
            if v & -v != v or nums[i] % prefix:  # nums[i] 不是 prefix 2 的幂次倍
                nums[i] //= 2
                ans += 1
            else:
                break
        nums[i] = nums[i].bit_length()  # 变成 2 进制位数
    nums.sort()
    print(ans + sum(abs(nums[i] - nums[n // 2]) for i in range(n)))
    return
