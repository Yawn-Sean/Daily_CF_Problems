def check(d):
  used = 0
  pos = [x[0] + d] * 3

  for i in range(1, len(x)):
    if x[i] - pos[used] > d:
      used += 1
      if used == 3:
        return None
      pos[used] = x[i] + d

  return pos


n = int(input())
x = list(map(int, input().split()))
x.sort()

l, r = 0, 1e9
res = [0.0] * 3
eps = 1e-7
while r - l > eps:
  mid = (l + r) / 2
  tmp = check(mid)

  if tmp is not None:
    r = mid
    res = tmp
  else:
    l = mid

print(f"{l:.6f}")
print(f"{res[0]:.6f} {res[1]:.6f} {res[2]:.6f}")
