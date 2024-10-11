t = RI()
ans = []
for _ in range(t):
    input()
    n = RI()
    li = []
    cnt = [0] * n
    for i in range(n):
        a = input()
        li.append([int(x) for x in a])
    #print(li)
    res = inf
    for i in range(n):
        for j in range(n):
            if li[i][j] == 1:
                cnt[(i - j) % n] += 1
    s1 = sum(cnt)
    s0 = n * n - s1
    for v in cnt:
        #枚举对角线
        res = min(res,n - v + s1 - v) #对角线上0变为1，非对角线1变为0
    ans.append(res)
print('\n'.join(map(str,ans)))

