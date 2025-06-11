l, r = map(int, input().split())
x = 10 ** len(str(r)) - 1
mid = x // 2
if l <= mid <= r:
  print(mid * (x - mid))
else:
  print(max(l * (x - l), r * (x - r)))
