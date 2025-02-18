n, h = MII()
if n == 2:
    print(0)
    print(1, 2)
else:
    a = LII()
    nums = sorted(a)
    ans = [1] * n
    chu = nums[-1] + nums[-2] - nums[0] - nums[1]
    mi = fmin(nums[0] + nums[1] + h, nums[1] + nums[2])
    mx = fmax(nums[0] + nums[-1] + h, nums[-1] + nums[-2])
    if chu <= mx - mi:
        print(chu)
        print(' '.join(map(str, ans)))
    else:
        print(mx - mi)
        for i in range(n):
            if a[i] == nums[0]:
                ans[i] = 2
                break
        print(' '.join(map(str, ans)))
