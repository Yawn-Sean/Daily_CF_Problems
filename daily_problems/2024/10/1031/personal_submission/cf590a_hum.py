n = int(input())
a = list(map(int, input().split()))

res = 0


def op(l, r):
  global res
  res = max(res, (r - l - 1) // 2)
  for j in range(l, (l + r) // 2):
    a[j] = a[l]
  for j in range((l + r) // 2, r):
    a[j] = a[r - 1]


l = 0
for i in range(1, n):
  if a[i] == a[i - 1]:
    op(l, i)
    l = i

op(l, n)

print(res)
print(*a)
