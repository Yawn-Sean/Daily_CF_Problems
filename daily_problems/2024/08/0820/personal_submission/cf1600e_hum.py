n = int(input())
a = list(map(int, input().split()))

i = 0
while i < n and a[i] < a[i + 1]:
  i += 1
j = n - 1
while j >= 0 and a[j] < a[j - 1]:
  j -= 1

if (i + 1) % 2 or (n - j) % 2:
  print("Alice")
else:
  print("Bob")
