import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

n, m = mii()
n -= 1
nums = []
for _ in range(m):
    _, x = mii()
    nums.append(x)
nums.sort(reverse=True)

ans = 0
for i, x in enumerate(nums):
    if i * (i+1) // 2 + (i//2 if i % 2 else 0) > n:
        break
    ans += x

print(ans)