n, q = map(int, input().split())
s = input()
next_pos = [[n] * (n + 2) for _ in range(26)]

for i in range(n - 1, -1, -1):
  for j in range(26):
    next_pos[j][i] = next_pos[j][i + 1]
  next_pos[ord(s[i]) - ord('a')][i] = i

base = 255


def f(x, y, z):
  return (x * base + y) * base + z


dp = [n] * (base ** 3)

dp[0] = -1

cur0 = cur1 = cur2 = 0
s0, s1, s2 = [], [], []

for _ in range(q):
  que = list(input().split())
  if que[0] == '-':

    if que[1] == '1':
      s0.pop()
      cur0 -= 1
    elif que[1] == '2':
      s1.pop()
      cur1 -= 1
    else:
      s2.pop()
      cur2 -= 1

  else:
    c = ord(que[2]) - ord('a')
    if que[1] == '1':
      for i in range(cur1 + 1):
        for j in range(cur2 + 1):
          dp[f(cur0 + 1, i, j)] = next_pos[c][dp[f(cur0, i, j)] + 1]

          if i and next_pos[s1[i - 1]][dp[f(cur0 + 1, i - 1, j)] + 1] < dp[f(cur0 + 1, i, j)]:
            dp[f(cur0 + 1, i, j)] = next_pos[s1[i - 1]][dp[f(cur0 + 1, i - 1, j)] + 1]

          if j and next_pos[s2[j - 1]][dp[f(cur0 + 1, i, j - 1)] + 1] < dp[f(cur0 + 1, i, j)]:
            dp[f(cur0 + 1, i, j)] = next_pos[s2[j - 1]][dp[f(cur0 + 1, i, j - 1)] + 1]
      s0.append(c)
      cur0 += 1
    elif que[1] == '2':
      for i in range(cur0 + 1):
        for j in range(cur2 + 1):
          dp[f(i, cur1 + 1, j)] = next_pos[c][dp[f(i, cur1, j)] + 1]

          if i and next_pos[s0[i - 1]][dp[f(i - 1, cur1 + 1, j)] + 1] < dp[f(i, cur1 + 1, j)]:
            dp[f(i, cur1 + 1, j)] = next_pos[s0[i - 1]][dp[f(i - 1, cur1 + 1, j)] + 1]

          if j and next_pos[s2[j - 1]][dp[f(i, cur1 + 1, j - 1)] + 1] < dp[f(i, cur1 + 1, j)]:
            dp[f(i, cur1 + 1, j)] = next_pos[s2[j - 1]][dp[f(i, cur1 + 1, j - 1)] + 1]

      s1.append(c)
      cur1 += 1

    else:
      for i in range(cur0 + 1):
        for j in range(cur1 + 1):
          dp[f(i, j, cur2 + 1)] = next_pos[c][dp[f(i, j, cur2)] + 1]

          if i and next_pos[s0[i - 1]][dp[f(i - 1, j, cur2 + 1)] + 1] < dp[f(i, j, cur2 + 1)]:
            dp[f(i, j, cur2 + 1)] = next_pos[s0[i - 1]][dp[f(i - 1, j, cur2 + 1)] + 1]

          if j and next_pos[s1[j - 1]][dp[f(i, j - 1, cur2 + 1)] + 1] < dp[f(i, j, cur2 + 1)]:
            dp[f(i, j, cur2 + 1)] = next_pos[s1[j - 1]][dp[f(i, j - 1, cur2 + 1)] + 1]

      s2.append(c)
      cur2 += 1

  print('YES' if dp[f(cur0, cur1, cur2)] < n else 'NO')
