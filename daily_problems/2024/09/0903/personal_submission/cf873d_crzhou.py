n, cnt = MII()

if cnt % 2 == 0:
    print(-1)

else:
    nums = [i for i in range(1, n + 1)]

    def dfs(l: int, r: int) -> None:
        global cnt
        if l + 1 == r or cnt == 0:
            return
        mid = (l + r) // 2
        nums[mid - 1], nums[mid] = nums[mid], nums[mid - 1]
        cnt -= 2
        dfs(l, mid)
        dfs(mid, r)

    cnt -= 1
    dfs(0, n)

    print(' '.join(map(str, nums)) if cnt == 0 else -1)
