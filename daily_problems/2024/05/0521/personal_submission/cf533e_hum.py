n = int(input())
s1 = input()
s2 = input()
tmp = []
for i in range(n):
  if s1[i] != s2[i]:
    tmp.append(i)

i, j = tmp[0], tmp[-1]
res = 0
if s1[i + 1:j + 1] == s2[i:j]:
  res += 1
if s1[i:j] == s2[i + 1:j + 1]:
  res += 1
print(res)
