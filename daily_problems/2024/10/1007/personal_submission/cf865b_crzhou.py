import sys
input = sys.stdin.read
data = input().splitlines()

n, m = map(int, data[0].split())
ans = 0
b1 = []
b2 = []
s1 = 0
s2 = 0

for i in range(1, n + 1):
    c, a, b = map(int, data[i].split())
    if a > b:
        ans += a * c
        b1.append((a - b, c))
        s1 += c
    else:
        ans += b * c
        b2.append((b - a, c))
        s2 += c

s1 %= m
s2 %= m

if s1 + s2 > m:
    print(ans)
    exit()

b1.sort()
b2.sort()

c1 = 0
for k1, k2 in b1:
    c1 += min(k2, s1) * k1
    s1 -= min(k2, s1)
    if s1 <= 0:
        break

c2 = 0
for k1, k2 in b2:
    c2 += min(k2, s2) * k1
    s2 -= min(k2, s2)
    if s2 <= 0:
        break

print(ans - min(c1, c2))
