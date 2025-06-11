n = int(input())
a = list(map(int, input().split()))

y = 1

for i in range(n - 1):
  if a[i] == a[i + 1]:
    print("NO")
    exit()
  if abs(a[i] - a[i + 1]) != 1:
    y = abs(a[i] - a[i + 1])

for i in range(n - 1):
  if abs(a[i] - a[i + 1]) != 1 and abs(a[i] - a[i + 1]) != y:
    print("NO")
    exit()
  if y != 1 and abs(a[i] - a[i + 1]) != y and (a[i] - 1) // y != (a[i + 1] - 1) // y:
    print("NO")
    exit()

print("YES")
print(1000000000, y)
