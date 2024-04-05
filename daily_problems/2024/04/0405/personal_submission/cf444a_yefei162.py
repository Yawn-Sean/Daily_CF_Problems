n, m = MI()
nums = LI()
mx = 0
for _ in range(m):
    u, v, w = MI()
    mx = max(mx, (nums[u - 1] + nums[v - 1]) / w)
print(mx)
