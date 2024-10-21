n = II()
nums = LII()

ml, mr = defaultdict(lambda: -1), defaultdict(lambda: -1)
for i, x in enumerate(nums):
    if ml[x] == -1:
        ml[x] = i
        mr[x] = i
    else:
        mr[x] = i

f = [0] * (n + 1)
for i in range(n):
    tor = 0
    tmpl = tmpr = i
    s = set()
    for j in range(i, -1, -1):
        if nums[j] not in s:
            tor ^= nums[j]
            s.add(nums[j])
        tmpl = fmin(tmpl, ml[nums[j]])
        tmpr = fmax(tmpr, mr[nums[j]])
        f[i + 1] = fmax(f[i + 1], f[j])
        if tmpl == j and tmpr == i:
            f[i + 1] = fmax(f[i + 1], f[j] + tor)

print(f[-1])
