n, A, cf, cm, m = map(int, input().split())
a = list(map(int, input().split()))
cnt = a.count(A)
a = [(v, i) for i, v in enumerate(a)]
a.sort()

s = [0]
for v, i in a:
  s.append(s[-1] + v)

a.append((A, n))

res = cnt * cf + a[0][0] * cm
now = (cnt, a[0][0])

suf = 0
for i in range(n - cnt, -1, -1):
  suf += A - a[i][0]
  if m >= suf:
    last = m - suf
    l, r = a[0][0], A
    while l < r:
      mi = l + r + 1 >> 1
      left, right = -1, i - 1
      while left < right:
        mid = left + right + 1 >> 1
        if a[mid][0] >= mi:
          right = mid - 1
        else:
          left = mid

      if last >= mi * (left + 1) - (s[left + 1] - s[0]):
        l = mi
      else:
        r = mi - 1

    if l * cm + (n - i) * cf > res:
      res = l * cm + (n - i) * cf
      now = (n - i, l)

  else:
    break

b = [0] * n
for i in range(n):
  if n - i <= now[0]:
    b[a[i][1]] = A
  else:
    b[a[i][1]] = max(now[1], a[i][0])

print(res)
print(*b)
