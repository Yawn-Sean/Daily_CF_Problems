n, k = MII()
nums = LII()

cnt = [0] * (k + 1)

i = 0
while i < n:
    j = i
    x = nums[i]
    while j < n and nums[j] == x:
        j += 1
    if j < n and i and nums[j] == nums[i - 1]:
        cnt[x] += 2
    else:
        cnt[x] += 1
    i = j
    
print(cnt.index(max(cnt)))
