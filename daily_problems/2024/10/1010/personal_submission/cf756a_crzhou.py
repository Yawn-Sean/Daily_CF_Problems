n = II()
nums = LGMI()
bs = LII()
ans = (sum(bs) + 1) % 2

cnt = 0
vis = [False] * n
for i in range(n):
    if vis[i]:
        continue
    cnt += 1
    while not vis[i]:
        vis[i] = True
        i = nums[i]

if cnt == 1:
    print(ans)
else:
    print(ans + cnt)
