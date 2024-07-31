import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
s = input()
s = [ord(c) - ord('a') for c in s]
tmp = [[0] * (n + 1) for _ in range(26)]
for i in range(26):
  for j in range(1, n + 1):
    l, r = 0, 0
    cnt = 0
    while l < n:
      while r < n and cnt + (0 if s[r] == i else 1) <= j:
        cnt += (0 if s[r] == i else 1)
        r += 1

      tmp[i][j] = max(tmp[i][j], r - l)
      cnt -= (0 if s[l] == i else 1)
      l += 1

q = int(input())
res = []
for _ in range(q):
  m, c = input().split()
  res.append(tmp[ord(c) - ord('a')][int(m)])

print('\n'.join(map(str, res)))
