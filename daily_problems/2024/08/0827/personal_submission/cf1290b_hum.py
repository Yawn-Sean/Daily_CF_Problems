import sys

input = lambda: sys.stdin.readline().rstrip()
s = input()
s = [ord(c) - ord('a') for c in s]
n = len(s)
acc = [[0] * 26 for _ in range(n + 1)]

for i in range(n):
  acc[i + 1][:] = acc[i][:]
  acc[i + 1][s[i]] += 1

q = int(input())

for _ in range(q):
  l, r = map(lambda x: int(x) - 1, input().split())
  cnt = 0
  for i in range(26):
    cnt += 1 if acc[r + 1][i] - acc[l][i] > 0 else 0

  if l == r or s[l] != s[r] or cnt >= 3:
    print("Yes")
  else:
    print("No")
