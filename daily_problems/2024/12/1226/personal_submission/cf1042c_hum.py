n = int(input())
l = list(map(int, input().split(" ")))
# print(l)
zero = []
minus = []
inf = 10 ** 10
max_minus, idx = -inf, -1
for i in range(n):
  if l[i] == 0:
    zero.append(i)
  elif l[i] < 0:
    minus.append(i)
    if l[i] > max_minus:
      max_minus = l[i]
      idx = i

if len(minus) % 2:
  if len(zero) > 0:
    print(f"1 {idx + 1} {zero[0] + 1}")
  else:
    print(f"2 {idx + 1}")
  l[idx] = inf

if len(zero) > 0:
  for i in range(1, len(zero)):
    print(f"1 {zero[i] + 1} {zero[0] + 1}")
    l[zero[i]] = inf

  if len(zero) + len(minus) < n or len(minus) >= 2:
    print(f"2 {zero[0] + 1}")
    l[zero[0]] = inf

for i in range(n):
  if l[i] != inf:
    for j in range(i + 1, n):
      if l[j] != inf:
        print(f"1 {j + 1} {i + 1}")
    break
