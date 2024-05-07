# submission: https://codeforces.com/problemset/submission/989/259711638

def main():
  a, b, c, d = MII()
  ans = [[''] * 50 for _ in range(50)]
  for i in range(25):
      for j in range(25):
          ans[i][j] = 'A'
          ans[i][j + 25] = 'B'
          ans[i + 25][j] = 'C'
          ans[i + 25][j + 25] = 'D'
  a -= 1
  b -= 1
  c -= 1
  d -= 1

  # A 填到 B
  for i in range(1, 25, 2):
      for j in range(26, 50, 2):
          if a:
              ans[i][j] = 'A'
              a -= 1
          else:
              break
  # B 填到 C
  for i in range(26, 50, 2):
      for j in range(1, 25, 2):
          if b:
              ans[i][j] = 'B'
              b -= 1
          else:
              break
  
  # C 填到 D
  for i in range(26, 50, 2):
      for j in range(26, 50, 2):
          if c:
              ans[i][j] = 'C'
              c -= 1
          else:
              break
  
  # D 填到 A
  for i in range(1, 25, 2):
      for j in range(1, 25, 2):
          if d:
              ans[i][j] = 'D'
              d -= 1
          else:
              break
  print(50, 50)
  print(*[''.join(ans[i]) for i in range(50)], sep='\n')

main()

