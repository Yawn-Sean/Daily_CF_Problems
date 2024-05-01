n,k = RII()
li = RILIST()
tmp1, tmp2 = [], []
cnt = 0
for x in li:
    if x >= 0:
        cnt += 1
    else:
        k -= 1
        tmp1.append(cnt)
        cnt = 0
if tmp1: tmp2.append(cnt)
if k < 0:
    print(-1)
    exit()
opt = 2 * (len(tmp1))  #初始情况下，遇到一个负数就要换两次胎，初始位2 * (len(tmp1))
if opt == 0:
    print(0)
    exit()
#print(tmp1,tmp2)
ans = opt
tmp1 = tmp1[1:]  #第一次遇到<0 直接换冬季轮胎 不考虑间隔的
tmp1.sort()
t = k
#最后一次使用完冬季轮胎不更换 ，这样可以减少一次更换次数
k -= tmp2[-1]
if k >= 0:
    res = opt - 1
    for m in tmp1:
        if k >= m:
            k -= m
            res -= 2
    ans = min(ans,res)

#最后一次使用完冬季轮胎依然更换
res = opt
for m in tmp1:
    if t >= m:
        t -= m
        res -= 2
ans = min(ans,res)
print(ans)


