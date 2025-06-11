import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

n, k = mii()
nums = lii()
nums.sort()
ans, target = 1, nums[0]
l = 0
s = 0
for r, x in enumerate(nums):
    s += x
    while (r-l+1) * x - s > k:
        s -= nums[l]
        l += 1
    if r-l+1 > ans:
        ans = r-l+1
        target = x

print(ans, target)