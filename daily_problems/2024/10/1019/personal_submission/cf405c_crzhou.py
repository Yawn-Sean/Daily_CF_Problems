n = II()
nums = []
for _ in range(n):
    nums.append(LII())
cur = 0
for i in range(n):
    for j in range(n):
        cur += nums[i][j] * nums[j][i]
cur %= 2

ans = []
q = II()
for _ in range(q):
    qq = LII()
    if len(qq) == 1:
        ans.append(cur)
    else:
        cur += 1
        cur %= 2
    
print("".join(map(str, ans)))
