from collections import Counter
from math import ceil

nn = int(input())

tests = [(input(), list(map(int, input().split()))) for _ in range(nn)]

for n, arr in tests:
  cnt = Counter(arr)

  # 最小的频率 v, 枚举 k: v+1 -> 2
  min_v = min(cnt.values())
  for k in range(min_v, 0, -1):
    ans = 0
    for v in cnt.values():
      q, r = divmod(v, k)
      if r > q:
        break
      ans += int(ceil(v / (k + 1)))
    else:
      print(ans)
      break
