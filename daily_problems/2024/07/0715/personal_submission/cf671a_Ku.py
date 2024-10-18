ax,ay,bx,by,tx,ty = RII()
n = RI()
a,b = [],[]
c,d = [],[]
for i in range(n):
    x,y = RII()
    dis_a = sqrt((ax-x) ** 2 + (ay-y) ** 2)
    dis_b = sqrt((bx - x) ** 2 + (by - y) ** 2)
    dis = sqrt((tx- x) ** 2 + (ty - y) ** 2)
    a.append(((dis_a - dis),i))
    b.append(((dis_b - dis),i))
    c.append((dis_a,dis))
    d.append((dis_b,dis))
a.sort()
b.sort()

if a[0][1] != b[0][1]:
    i,j = a[0][1],b[0][1]
    ans = c[i][0] + c[i][1]
    ans += (d[j][0] + d[j][1])
    res1 = c[i][0] + c[i][1]
    res2 = d[j][0] + d[j][1]
    for x in range(n):
        if x != i and x != j:
            ans += 2 * c[x][1]
            res1 += 2 * c[x][1]
            res2 += 2 * c[x][1]
        elif x == j:
            res1 += 2 * c[j][1]
        elif x == i:
            res2 += 2 * c[i][1]
    ans = min(ans,res1,res2)


else:
    if len(a) == len(b) == 1:
        ans = min(c[0][0] + c[0][1], d[0][0] + d[0][1])
    else:
        i,j = a[0][1],b[1][1]
        res1 = c[i][0] + c[i][1]
        res2 = d[i][0] + d[i][1]
        ans = c[i][0] + c[i][1] + d[j][0] + d[j][1]
        for x in range(n):
            if x != i and x != j:
                ans += 2 * c[x][1]
                res1 += 2 * c[x][1]
                res2 += 2 * c[x][1]
            elif x == j:
                res1 += 2 * c[j][1]
                res2 += 2 * c[j][1]

        i, j = a[1][1], b[0][1]
        res = c[i][0] + c[i][1] + d[j][0] + d[j][1]
        for x in range(n):
            if x != i and x != j:
                res += 2 * c[x][1]

        ans = min(ans,res,res1,res2)
print(ans)
