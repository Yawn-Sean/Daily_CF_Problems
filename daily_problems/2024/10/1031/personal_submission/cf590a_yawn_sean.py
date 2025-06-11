def main():
    n = II()
    nums = LII()

    ans = 0

    def op(l, r):
        global ans
        ans = fmax(ans, (r - l - 1) // 2)
        for j in range(l, (l + r) // 2):
            nums[j] = nums[l]
        for j in range((l + r) // 2, r):
            nums[j] = nums[r - 1]

    l = 0
    for i in range(1, n):
        if nums[i] == nums[i - 1]:
            op(l, i)
            l = i

    op(l, n)

    print(ans)
    print(' '.join(map(str, nums)))