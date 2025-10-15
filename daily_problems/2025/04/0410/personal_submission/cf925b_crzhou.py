n, x1, x2 = MII()
c = LII()

idx = list(range(n))
idx.sort(key=lambda x: c[x])


flg = False
for i in range(n - 1, -1, -1):
    if (n - i) * c[idx[i]] >= x2:
        flg = True
        ans2 = i
        break
if flg:
    flg = False
    for i in range(ans2 - 1, -1, -1):
        if (ans2 - i) * c[idx[i]] >= x1:
            flg = True
            ans1 = i
            break
if flg:
    idx = [i + 1 for i in idx]
    print("Yes")
    print(ans2 - ans1, n - ans2)
    print(*idx[ans1: ans2])
    print(*idx[ans2: n])

else:
        
    flg = False
    for i in range(n - 1, -1, -1):
        if (n - i) * c[idx[i]] >= x1:
            flg = True
            ans2 = i
            break
    if flg:
        flg = False
        for i in range(ans2 - 1, -1, -1):
            if (ans2 - i) * c[idx[i]] >= x2:
                flg = True
                ans1 = i
                break
    if flg:
        idx = [i + 1 for i in idx]
        print("Yes")
        print(n - ans2, ans2 - ans1)
        
        print(*idx[ans2: n])
        print(*idx[ans1: ans2])
    else:
        print("No")
