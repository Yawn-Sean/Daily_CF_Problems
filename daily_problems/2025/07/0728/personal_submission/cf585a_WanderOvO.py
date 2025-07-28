"""
n = 4000，直接模拟即可
"""

n = int(input())
vs = []
ds = []
ps = []

for i in range(n):
    v, d, p = map(int, input().split())
    vs.append(v)
    ds.append(d)
    ps.append(p)

leave = [False] * n
res = []
for i in range(n):
    if leave[i]:
        continue

    leave[i] = True
    res.append(i + 1)
    v = vs[i]
    for j in range(i + 1, n):
        if v <= 0:
            break
        if leave[j]:
            continue
        ps[j] -= v
        v -= 1

    for j in range(i + 1, n):
        if not leave[j] and ps[j] < 0:
            leave[j] = True
            d = ds[j]
            for k in range(j + 1, n):
                ps[k] -= d

print(len(res))
print(*res)
