n, m = MII()
nums = []

for _ in range(m):
    _, x = MII()
    nums.append(x)

nums.sort(reverse=True)
ans = 0

for i in range(1, m + 1):
    if i % 2 == 1:
        tmp = i * (i - 1) // 2 + 1
    else:
        tmp = i * (i - 1) // 2 + i // 2
    if tmp > n:
        break
    ans += nums[i - 1]

print(ans)
