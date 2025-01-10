n, m = map(int, input().split())
inf = 10 ** 9

ops = []
for _ in range(m):
  ops.append(tuple(map(int, input().split())))

cur_diff = [0] * n
res = [inf] * n

for i in range(m):
  if ops[i][0] == 1:
    for j in range(ops[i][1] - 1, ops[i][2]):
      cur_diff[j] += ops[i][3]
  else:
    for j in range(ops[i][1] - 1, ops[i][2]):
      res[j] = min(res[j], ops[i][3] - cur_diff[j])

tmp = res[:]
for i in range(m):
  if ops[i][0] == 1:
    for j in range(ops[i][1] - 1, ops[i][2]):
      tmp[j] += ops[i][3]
  else:
    v = -inf
    for j in range(ops[i][1] - 1, ops[i][2]):
      v = max(v, tmp[j])
    if v != ops[i][3]:
      exit(print('NO'))

print('YES')
print(*res)
