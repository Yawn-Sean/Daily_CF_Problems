n = int(input())
s = input()
s = [ord(c) - ord('a') for c in s]

for i in range(25, 0, -1):
  stack = []
  for j in range(len(s)):
    if stack and stack[-1] == s[j] - 1 and s[j] == i:
      continue
    while stack and stack[-1] - 1 == s[j] and stack[-1] == i:
      stack.pop()
    stack.append(s[j])

  s = stack

print(n - len(s))
