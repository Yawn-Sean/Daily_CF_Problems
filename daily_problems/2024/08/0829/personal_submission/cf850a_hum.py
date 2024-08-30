n = int(input())
if n >= 34:
  print("0")
  exit()

ps = []
for _ in range(n):
  a = list(map(int, input().split()))
  ps.append(a)

res = []


def check(i):
  for j in range(n):
    for k in range(j):
      cur = 0
      for l in range(5):
        cur += (ps[i][l] - ps[j][l]) * (ps[i][l] - ps[k][l])
      if cur > 0:
        return False
  return True


for i in range(n):
  if check(i):
    res.append(i + 1)

print(len(res))
print(*res)
