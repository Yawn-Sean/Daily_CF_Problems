from math import inf
n, l = map(int, input().split())
c = list(map(int, input().split()))

vol = 1
cheapest = inf
cone = -1
cost = []
for i in range(n):
    per_vol = c[i] / vol
    cost.append((per_vol, vol, c[i]))
    vol <<= 1
cost.sort()

ans = inf
min_ = pow(2, 30)
used = 0
for _, v, ci in cost:
    if v > min_:
        continue
    ans = min(ans, used + ((l-1) // v + 1) * ci)
    used += l // v * ci
    l = l % v
print(ans)
