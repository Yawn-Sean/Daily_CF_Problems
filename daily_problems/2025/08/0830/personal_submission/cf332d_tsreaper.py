import sys
inp = iter(sys.stdin.read().split())

n = int(next(inp))
K = int(next(inp))

fac = [1]
for i in range(1, n + 1):
    fac.append(fac[i - 1] * i)

A = [0] * (n + 1)
deg = [0] * (n + 1)
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        x = int(next(inp))
        if x < 0:
            continue
        A[i] += x
        A[j] += x
        deg[i] += 1
        deg[j] += 1

ans1, ans2 = 0, 0
for i in range(1, n + 1):
    if deg[i] < K:
        continue
    t = fac[deg[i] - 1] // fac[deg[i] - K]
    ans1 += t * A[i]
    ans2 += t * deg[i]
print(ans1 * K // ans2)
