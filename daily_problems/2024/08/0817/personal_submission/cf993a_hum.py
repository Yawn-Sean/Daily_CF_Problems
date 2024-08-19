a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = min(a[0::2])
d = max(a[0::2])
e = min(a[1::2])
f = max(a[1::2])
g = sum(b[0::2]) // 4
h = sum(b[1::2]) // 4
r = abs(b[0] - g) + abs(b[1] - h)

for i in range(c, d + 1):
  for j in range(e, f + 1):
    if abs(i - g) + abs(j - h) <= r:
      print("YES")
      exit()
print("NO")
