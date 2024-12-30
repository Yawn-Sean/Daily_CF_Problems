from bisect import bisect_right, bisect_left
from itertools import accumulate

t = int(input())
for _ in range(t):
  n, q = map(int, input().split())
  a = list(map(int, input().split()))
  a.sort()
  s = list(accumulate(a, initial=0))
  nums = set()
  stack = [(0, n - 1)]
  while stack:
    l, r = stack.pop()
    nums.add(s[r + 1] - s[l])
    if a[l] != a[r]:
      v = (a[l] + a[r]) // 2
      mid = bisect_right(a, v)
      stack.append((l, mid - 1))
      stack.append((mid, r))

  for _ in range(q):
    x = int(input())
    if x in nums:
      print("Yes")
    else:
      print("No")
