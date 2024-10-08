n, m, a = map(int, input().split())
b = list(map(int, input().split()))
p = list(map(int, input().split()))
b.sort(reverse=True)
p.sort()

def check(x):
  last = a
  for i in range(x):
    j = x - i - 1
    if b[j] + last < p[i]:
      return False
    last += min(0, b[j] - p[i])
    j -= 1
  return True


l, r = 0, min(n, m)
while l < r:
  mid = l + r + 1 >> 1
  if check(mid):
    l = mid
  else:
    r = mid - 1

print(l, max(0, sum(p[:l]) - a))
