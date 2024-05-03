n, m = map(int, input().split())
a = list(map(int, input().split()))


def check(mid):
  j = 0
  for i in range(n):
    if a[i] <= j:
      if j > a[i] + mid:
        return False
    else:
      if a[i] + mid >= m:
        x = (a[i] + mid) % m
        if x < j:
          j = a[i]
      else:
        j = a[i]
  return True


l, r = 0, m
while l < r:
  mid = l + r >> 1
  if check(mid):
    r = mid
  else:
    l = mid + 1

print(l)
