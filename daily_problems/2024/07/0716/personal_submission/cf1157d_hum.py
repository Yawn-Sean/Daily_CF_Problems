n, k = map(int, input().split())
if n < (k + 1) * k // 2:
  print("NO")
else:
  s = (k + 1) * k // 2
  x = (n - s) // k
  res = list(range(1 + x, k + 1 + x))
  last = n - s - k * x

  while last:
    for i in range(k - 1, 0, -1):
      if res[i] + 1 <= 2 * res[i - 1]:
        res[i] += 1
        last -= 1
        break
    else:
      if last > 0:
        print("NO")
        exit()

  print("YES")
  print(*res)
