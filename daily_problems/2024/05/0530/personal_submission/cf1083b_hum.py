n, k = map(int, input().split())
s = input()
t = input()

res = 0
cur = 1
for x, y in zip(s, t):
  if cur > k:
    res += k
    continue

  cur = 2 * cur
  if x == 'b':
    cur -= 1
  if y == 'a':
    cur -= 1
  res += min(cur, k)

print(res)
