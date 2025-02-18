n = II()
tmp = []

for _ in range(n):
    x, y = MII()
    the = math.atan2(y, x)

    # 将弧度转换为角度
    t = (math.degrees(the) + 360) % 360

    tmp.append(t)

tmp.sort()
tmp = tmp + [tmp[0] + 360]
ans = 360
for i in range(n):
    ans = min(ans, 360 - tmp[i + 1] + tmp[i])
print(ans)
