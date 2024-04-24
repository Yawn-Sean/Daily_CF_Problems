q = int(input())


def h(s, t):
  j = 0
  for i in range(len(t)):
    while j < len(s) and s[j] != t[i]:
      j += 1
    if j == len(s):
      return i
    j += 1
  return len(t)


for _ in range(q):
  n = int(input())
  s, t = input(), input()
  s = [ord(c) - ord('a') for c in s]
  t = [ord(c) - ord('a') for c in t]
  if sorted(s) != sorted(t):
    print(-1)
    continue
  res = n + 1
  for i in range(n):
    cur = h(s, t[i:])
    res = min(res, n - cur)
  print(res)
