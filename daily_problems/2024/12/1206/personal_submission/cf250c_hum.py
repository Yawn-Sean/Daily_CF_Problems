n, k = map(int, input().split())

a = list(map(lambda x: int(x) - 1, input().split()))

b = []
last = -1
for i in range(n):
  if a[i] != last:
    b.append(a[i])
  last = a[i]

cnt = [0] * k
cnt[b[0]] += 1
cnt[b[-1]] += 1
for i in range(1, len(b) - 1):
  if b[i - 1] != b[i + 1]:
    cnt[b[i]] += 1
  else:
    cnt[b[i]] += 2

res = 0
for i in range(k):
  if cnt[i] > cnt[res]:
    res = i

print(res + 1)
