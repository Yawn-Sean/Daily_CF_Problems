from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
acc = list(accumulate(a))
acc.reverse()
acc.append(0)
a.reverse()

s = input()
s = s[::-1]

t = 0
res = 0
for i in range(n):
  if s[i] == '1':
    res = max(res, acc[i + 1] + t)
  t += a[i] * int(s[i])

res = max(res, t)
print(res)