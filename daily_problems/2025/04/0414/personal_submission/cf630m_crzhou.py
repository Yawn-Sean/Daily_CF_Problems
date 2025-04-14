x = II() % 360
tmp = 360
res = 0
for i in range(4):
    cur = min(abs(i * 90 - x), abs(360 + i * 90 - x))
    if cur < tmp:
        tmp = cur
        res = i
print(res)
