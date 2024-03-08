n = int(input())
a = list(map(int, input().split()))
a = [(v, i) for i, v in enumerate(a)]
a.sort()
if n <= 3:
  print(1)
  exit()


def check(d, arr):
  for i in range(len(arr) - 1):
    if arr[i + 1][0] - arr[i][0] != d:
      return False
  return True


ans = 0


def check2(d, arr):
  global ans
  for i in range(len(arr) - 1):
    if arr[i + 1][0] - a[i][0] != d:
      if check(d, arr[:i + 1] + (a[i + 2:] if i + 2 < len(arr) else [])):
        ans = arr[i + 1][1]
        return True
      else:
        return False
  return True


if check(a[2][0] - a[1][0], a[1:]):
  print(a[0][1] + 1)
elif check(a[2][0] - a[0][0], [a[0]] + a[2:]):
  print(a[1][1] + 1)
elif check2(a[1][0] - a[0][0], a):
  print(ans + 1)
else:
  print(-1)
