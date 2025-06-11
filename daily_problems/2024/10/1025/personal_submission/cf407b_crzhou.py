n = II()
nums = LII()
steps = [0] * (n + 1)
for i in range(1, n + 1):
    steps[i] = (steps[i - 1] * 2 - steps[nums[i - 1] - 1] + 2) % MOD
print(steps[-1])
