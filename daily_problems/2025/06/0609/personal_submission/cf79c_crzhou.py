s = I()
n = II()
nums = []
for _ in range(n):
    nums.append(I())

ans0 = ans1 = 0
l = 0
for r in range(len(s)):
    for x in nums:
        if x == s[fmax(0, r - len(x) + 1):r + 1]:
            l = fmax(l, r - len(x) + 2)
    if ans0 < r - l + 1:
        ans0 = r - l + 1
        ans1 = l
        
print(ans0, ans1)
