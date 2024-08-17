n, p = map(int, input().split())
s = input()
s = [ord(c) - ord('a') for c in s]

for i in range(n - 1, -1, -1):
  for j in range(s[i] + 1, p):
    if i - 1 >= 0 and j == s[i - 1]:
      continue
    if i - 2 >= 0 and j == s[i - 2]:
      continue
    s[i] = j

    for idx in range(i + 1, n):
      for j in range(p):
        if idx - 1 >= 0 and j == s[idx - 1]:
          continue
        if idx - 2 >= 0 and j == s[idx - 2]:
          continue
        s[idx] = j
        break
    print(''.join(chr(ord('a') + c) for c in s))
    exit()

print("NO")
exit()
