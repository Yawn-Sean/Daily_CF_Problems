import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

n, q = mii()
nums = [0] + lii()
rights = [0] * (n+1)
l, r = 1, 1
while l <= n:
    while r <= n and nums[r] == nums[l]:
        r += 1
    while l < r:
        rights[l] = r
        l += 1

for _ in range(q):
    l, r, x = mii()
    if nums[l] != x:
        print(l)
    elif rights[l] <= r:
        print(rights[l])
    else:
        print(-1)