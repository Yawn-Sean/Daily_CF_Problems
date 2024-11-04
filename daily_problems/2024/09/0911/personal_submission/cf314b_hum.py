b, d = map(int, input().split())
a = input()
c = input()
m = len(c)

to_idx = list(range(m))
cnt = [0] * m

for i in range(m):
  for ch in a:
    if ch == c[to_idx[i]]:
      to_idx[i] += 1
      if to_idx[i] == m:
        to_idx[i] = 0
        cnt[i] += 1

idx = cur = 0
for _ in range(b):
  cur += cnt[idx]
  idx = to_idx[idx]

print(cur // d)
