n = int(input()) + 2
s = "SS" + input()

tot = s.count('G')

i = 0
last = 0
res = 0
while i < n:
  j = i
  if s[i] == 'G':
    while j + 1 < n and s[j + 1] == 'G':
      j += 1
    cur = j - i + 1
    res = max(res, cur + (1 if tot > cur else 0))

    if s[i - 2] == "G":
      res = max(res, last + cur + (1 if tot > last + cur else 0))
    last = cur
  i = j + 1

print(res)
