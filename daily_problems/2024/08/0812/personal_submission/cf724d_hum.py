m = int(input())
s = [ord(c) - ord('a') for c in input()]

n = len(s)


def check(c):
  res = [-1]
  for i in range(n):
    if s[i] <= c:
      res.append(i)
  res.append(n)

  for i in range(1, len(res)):
    if res[i] - res[i - 1] > m:
      return False
  return True


for c in range(26):
  if check(c):
    res = []
    pre = -1
    pre_c = -1

    for i in range(n):
      if s[i] < c:
        res.append(chr(s[i] + ord('a')))
        pre = i
      elif s[i] == c:
        pre_c = i
      if i - pre >= m:
        res.append(chr(s[pre_c] + ord('a')))
        pre = pre_c
    res.sort()
    print(''.join(res))
    exit()
