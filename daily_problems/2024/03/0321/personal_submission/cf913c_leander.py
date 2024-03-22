import sys
input = lambda: sys.stdin.readline().strip()

n, l = map(int, input().split())
cost = list(map(int, input().split()))

c = cost + [-1] * (35-len(cost))
for i in range(1, 35):
    if c[i] == -1:
        c[i] = c[i-1] * 2
    else:
        c[i] = min(c[i], c[i-1] * 2)

idx = 0
ans = 0
while l or idx < 35:
    if l & 1:
        ans += c[idx]
    else:
        ans = min(ans, c[idx])
    l >>= 1
    idx += 1
# ans = min(ans, c[idx])
print(ans)
