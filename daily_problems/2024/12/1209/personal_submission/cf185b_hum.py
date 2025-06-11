s = int(input())
a, b, c = map(int, input().split())

if a or b or c:
  tot = a + b + c
  print(s * a / tot, s * b / tot, s * c / tot)
else:
  print(0, 0, s)
