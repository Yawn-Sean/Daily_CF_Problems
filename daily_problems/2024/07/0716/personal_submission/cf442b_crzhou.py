n = int(input())
p = list(map(float, input().split()))
p.sort(reverse=True)

p0, p1 = 1, 0
ans = 0
i = 0
while i < n and p0 > p1:
    p1 += p[i] * (p0 - p1)
    p0 *= 1 - p[i]
    ans = max(ans, p1)
    i += 1
print(ans)
