n = int(input())
x = list(map(int, input().split()))
v = list(map(int, input().split()))

idx = sorted(range(n), key=lambda i: x[i])

l = 0
r = 1e9
eps = 1e-6
inf = float('inf')


def check():
  left = -inf
  right = inf
  for i in range(n):
    l = x[idx[i]] - v[idx[i]] * mid
    r = x[idx[i]] + v[idx[i]] * mid
    if l > right:
      return False
    left = max(l, left)
    right = min(r, right)
  return True


while r - l > eps:
  mid = (l + r) / 2
  if check():
    r = mid
  else:
    l = mid

print(l)
