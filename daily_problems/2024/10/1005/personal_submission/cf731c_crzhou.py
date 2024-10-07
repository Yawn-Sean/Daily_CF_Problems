n, m, k = MII()
nums = LII()
p = list(range(n))
for _ in range(m):
    a, b = GMI()
    union(a, b)

cnts = [Counter() for _ in range(n)]
for i, x in enumerate(nums):
    cnts[find(i)][x] += 1

ans = 0
for c in cnts:
    if c:
        ans += max(c.values())
print(n - ans)
