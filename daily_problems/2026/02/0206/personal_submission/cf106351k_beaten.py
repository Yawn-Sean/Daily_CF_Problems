import math
M = 10**5
fac = [[] for _ in range(M + 1)]
for i in range(1, M + 1):
    for j in range(i, M + 1, i):
        fac[j].append(i)

n, x, y = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0] * (M + 1)
for v in a:
    cnt[v] += 1

ans = 0

for i in range(x, y + 1):
    if cnt[i] >= 2:
        ans += cnt[i] * (cnt[i] - 1) // 2

    facs = fac[i]
    m = len(facs)

    for j in range(m):
        for k in range(j):
            a1 = facs[j]
            a2 = facs[k]
            g = math.gcd(a1, a2)
            if g >= x and a1 * a2 // g == i:
                ans += cnt[a1] * cnt[a2]

print(ans)
