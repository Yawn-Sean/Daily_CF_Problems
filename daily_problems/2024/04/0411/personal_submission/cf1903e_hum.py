t = int(input())

for _ in range(t):

  n = int(input())
  x, y = map(int, input().split())
  s = (x + y) % 2
  t1, t2 = set(), set()


  def choose(t):
    global last
    while len(t) > 0:
      print(t.pop(), flush=True)
      last -= 1
      if last > 0:
        x = int(input())
        t1.discard(x)
        t2.discard(x)
        last -= 1


  for i in range(n):
    a, b = map(int, input().split())
    if (a + b) % 2 == s:
      t1.add(i + 1)
    else:
      t2.add(i + 1)

  if len(t1) >= len(t2):
    print("First", flush=True)
    last = n
    choose(t2)
    choose(t1)
  else:
    print("Second", flush=True)
    x = int(input())
    t1.discard(x)
    t2.discard(x)
    last = n - 1
    choose(t1)
    choose(t2)
