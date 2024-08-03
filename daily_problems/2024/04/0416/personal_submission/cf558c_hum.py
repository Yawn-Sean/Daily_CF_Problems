n = int(input())
a = list(map(int, input().split()))
mx = max(a)
cnt = [0] * (mx + 1)
for v in a:
  while v:
    cnt[v] += 1
    v >>= 1

pre = max(range(mx, 0, -1), key=lambda x: cnt[x])

res = 0
tmp = []

for v in a:
  for i in range(v.bit_length()):
    if v >> i == pre:
      v -= pre << i
      res += v.bit_length()
      tmp.append(i - v.bit_length())

tmp.sort()

print(sum(abs(x - tmp[n // 2]) for x in tmp) + res)
