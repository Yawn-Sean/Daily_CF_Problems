h, t = MII()

tmp = [t]
for _ in range(h):
    t = (t + 1) // 2
    tmp.append(t)

ans = 0
tmp = tmp[::-1]
flg = 0 

for i in range(1, h + 1):
    if tmp[i] == tmp[i - 1] * 2:
        if flg == 0:
            ans += (1 << (h - i + 1)) - 1
        flg = 0
    else:
        if flg == 1:
            ans += (1 << (h - i + 1)) - 1
        flg = 1
    ans += 1

print(ans)
