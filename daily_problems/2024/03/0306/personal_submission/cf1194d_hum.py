t = int(input())
for _ in range(t):

  n, k = map(int, input().split())
  if k % 3:
    if n % 3 == 0:
      print("Bob")
    else:
      print("Alice")
  else:
    r = n % (k + 1)
    if r % 3 == 0 and r != k:
      print("Bob")
    else:
      print("Alice")
