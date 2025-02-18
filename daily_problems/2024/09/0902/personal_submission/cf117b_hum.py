a, b, m = map(int, input().split())
x = 10 ** 9 % m
for i in range(1, min(m, a + 1)):
  cur = i * x % m
  if -cur % m > b:
    print(1, str(i).zfill(9))
    exit()

print(2)
