n, m = map(int, input().split())
val = list(map(int, input().split()))
res = 0
for _ in range(m):
    a, b, c = map(int, input().split())
    res = max(res, (val[a - 1] + val[b - 1]) / c)
print(res)
