t = II()
for _ in range(t):
    n = II()
    mx = [0] + [-1] * (n * 2)
    nums = LII()
    cur = 0
    for i in range(n):
        cur += 1 if nums[i] == 1 else -1
        mx[cur] = i + 1

    cur = 0
    ans = mx[0]  # ! wa
    for i in range(n * 2 - 1, n - 1, -1):
        cur += 1 if nums[i] == 2 else -1
        if mx[cur] != -1:
            ans = max(ans, mx[cur] + n * 2 - i)

    print(n * 2 - ans)
