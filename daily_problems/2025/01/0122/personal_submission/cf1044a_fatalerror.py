import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

inf = 10**9

m, n = mii()
vert = [ii() for _ in range(m)]
vert.sort()
vert.append(inf)
hori = []
for _ in range(n):
    x1, x2, y = mii()
    if x1 == 1:
        hori.append(x2)
hori.sort()
n = len(hori)

ans = n
j = 0
for i, x in enumerate(vert):
    while j < n and hori[j] < x:
        j += 1
    ans = min(ans, i+n-j)

print(ans)