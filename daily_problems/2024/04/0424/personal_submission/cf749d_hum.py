import sys

input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left

n = int(input())
bids = [[] for _ in range(n)]
max_bids = [-1] * n

for _ in range(n):
  person, bid = map(int, input().split())
  bids[person - 1].append(bid)
  max_bids[person - 1] = max(max_bids[person - 1], bid)

idx = sorted(range(n), key=lambda x: max_bids[x], reverse=True)

q = int(input())
for _ in range(q):
  absent = set(list(map(lambda x: int(x) - 1, input().split()))[1:])
  fir, sec = -1, -1
  for i in idx:
    if i not in absent:
      if fir == -1:
        fir = i
      elif sec == -1:
        sec = i
        break

  if fir == -1 or len(bids[fir]) == 0:
    print(0, 0)
    continue
  if sec == -1:
    print(fir + 1, bids[fir][0])
    continue
  sec_max = max_bids[sec]
  price = bids[fir][bisect_left(bids[fir], sec_max)]
  print(fir + 1, price)
