s = input()
for c in s:
  if s.count(c) == 2:
    break

i = s.index(c)
j = i + 1 + s[i + 1:].index(c)
if i + 1 == j:
  print("Impossible")
  exit(0)

s = s.replace(c, "", 1) * 3

mid = 13 + (i + j) // 2
print(s[mid - 13:mid])
print(s[mid:mid + 13][::-1])
