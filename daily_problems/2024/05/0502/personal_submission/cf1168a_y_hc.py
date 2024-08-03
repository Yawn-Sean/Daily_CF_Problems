def solve():
    n, m = MII()
    nums = LII()
    l, r = -1, m + 1

    while l + 1 != r:
        mid = l + r >> 1
        pre = 0
        for i in range(n):
            #把当前数变成大于等于pre的在范围之内的最小数字
            end = nums[i] + mid
            if end < pre and nums[i] < pre:
                l = mid
                break
            if end >= m and end % m >= pre: continue
            pre = max(pre, nums[i])
        else:
            r = mid

    print(r)

t = 1
for _ in range(t):
    solve()
