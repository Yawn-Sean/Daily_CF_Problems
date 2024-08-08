n, a, b, k = map(int, input().split())
s = input()
cnt = 0
res = []
for i in range(n):
  if s[i] == '1':
    cnt = 0
  else:
    cnt += 1
    if cnt == b:
      res.append(i)
      cnt = 0

print(len(res) - (a - 1))
for i in range(len(res) - (a - 1)):
  print(res[i] + 1, end=' ')
