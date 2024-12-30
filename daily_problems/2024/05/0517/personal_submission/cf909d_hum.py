s = input()
n = len(s)
i, j = 0, 0
st = []
while i < n:
  j = i
  while j + 1 < n and s[j + 1] == s[i]:
    j += 1
  st.append((j - i + 1, s[i]))
  i = j + 1

res = 0
while len(st) > 1:
  nst = []
  for i, (l, c) in enumerate(st):
    nl = l - 2
    if i == 0 or i == len(st) - 1:
      nl += 1
    if nl > 0:
      while nst and nst[-1][1] == c:
        nl += nst.pop()[0]
      nst.append((nl, c))
  st = nst
  res += 1

print(res)
