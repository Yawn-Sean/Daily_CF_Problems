n = int(input())
res = [-1] * (n + 1)
for i in range(n, -1, -1):
  if res[i] != -1:
    continue
  t = (1 << i.bit_length()) - 1
  res[t ^ i] = i
  res[i] = t ^ i

print(n * (n + 1))
print(*res)

a = 10 / 2 + 10 / 2
b = 10 / 3 + 10 / 3 + 9 / 3
print(a, b)
