# 难受，错在了去把所有点分为两类，不对其实也可以做
# 想的是二分后再处理，以为是n^2logn的复杂度。
# 正解：其实可以先去预处理不合法的，再二分；二分也不用，直接双指针
import sys
from collections import Counter
input = sys.stdin.readline
n, p = map(int, input().split())
d = [0] * n
cnt = Counter()

for _ in range(n):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    if x > y: x, y = y, x # 防止一类点存两遍
    d[x] += 1
    d[y] += 1
    cnt[(x, y)] += 1

# 因为后面要排序，所以得先减去不合法的，容斥定理
ans = 0
for x, y in cnt:
    if d[x] + d[y] >= p and d[x] + d[y] - cnt[(x, y)] < p:
        ans -= 1

d.sort()
# 双指针不一定要同向，只要它们行进的方向不会变就行了
l = 0
for r in range(n - 1, -1, -1):
    while l < r and d[l] + d[r] < p:
        l += 1
    if l == r: break # 没有满足要求的了
    ans += r - l

print(ans)