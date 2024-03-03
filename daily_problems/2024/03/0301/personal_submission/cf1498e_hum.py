n = int(input())
a = list(map(int, input().split()))

tmp = [(d, i) for i, d in enumerate(a)]
tmp.sort()

s = 0
u, v = -1, -1
last = -1
res = -1
for i in range(n):
  s += tmp[i][0]
  if s == (i + 1) * i // 2:
    if last != i - 1:
      cur = tmp[i][0] - tmp[last + 1][0]
      if cur > res:
        res = cur
        u, v = tmp[last + 1][1], tmp[i][1]

    last = i

print("!", u + 1, v + 1, flush=True)
