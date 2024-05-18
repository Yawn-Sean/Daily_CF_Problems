import sys

input = lambda: sys.stdin.readline().rstrip()


def f(s, last):
  if '?' not in s:
    if int(s) > last:
      return int(s)
    else:
      return -1

  if len(s) < len(str(last)):
    return -1
  elif len(s) > len(str(last)):
    if s[0] == '?':
      s = '1' + s[1:]
    s = s.replace('?', '0')
    return int(s)

  else:
    n = len(s)
    s = list(s)
    t = list(str(last))
    find = False
    stk = []
    for i in range(n):
      if s[i] == '?':
        stk.append(i)
      else:
        if s[i] > t[i]:
          find = True
          break
        elif s[i] < t[i]:
          find = False
          break

    if find:
      for i in stk:
        s[i] = t[i]
      s = ''.join(s).replace('?', '0')
      return int(s)
    else:
      if stk:
        while stk:
          i = stk.pop()
          if t[i] == '9':
            continue
          else:
            s[i] = str(int(t[i]) + 1)
            for i in stk:
              s[i] = t[i]
            s = ''.join(s).replace('?', '0')
            return int(s)

    return -1


n = int(input())
nums = [0]
for i in range(n):
  s = input()
  cur = f(s, nums[-1])
  if cur > 0:
    nums.append(cur)
  else:
    print('NO')
    exit()

print("YES")
print(*nums[1:], sep='\n')
