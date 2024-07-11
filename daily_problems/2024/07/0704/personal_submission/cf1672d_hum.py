import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))
  i = j = n - 1
  cnt = [0] * (n + 1)
  f = True
  while i >= 0 and j >= 0:
    while j - 1 >= 0 and b[j] == b[j - 1]:
      cnt[b[j]] += 1
      j -= 1

    if a[i] == b[j]:
      i -= 1
      j -= 1
    elif cnt[a[i]] > 0:
      cnt[a[i]] -= 1
      i -= 1
    else:
      f = False
      break
  if f:
    print("YES")
  else:
    print("NO")
