q = int(input())
b = "RGB"
for _ in range(q):
  n, k = map(int, input().split())
  a = input()
  res = n
  for x in range(3):
    s = [0]
    for i in range(n):
      if a[i] != b[(i + x) % 3]:
        s.append(s[-1] + 1)
      else:
        s.append(s[-1])
      if i >= k - 1:
        res = min(res, s[i + 1] - s[i + 1 - k])
  print(res)
