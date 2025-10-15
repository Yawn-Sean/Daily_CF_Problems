n = II()
a = LII()
if sum(a) < (n - 1) * 2:
    print("NO")
else:
    tmp1, tmp2 = [], []
    for i, x in enumerate(a):
        if x == 1:
            tmp1.append(i + 1)
        else:
            tmp2.append(i + 1)

    print("YES", fmin(n - 1, n - (len(tmp1) - 1)))
    print(n - 1)
            
    for i in range(fmin(len(tmp1), 2)):
        tmp = (len(tmp2) - i) % len(tmp2)
        print(tmp1[i], tmp2[tmp])

    for x, b in pairwise(tmp2):
        print(x, b)
        
    j = 0
    for i in range(2, len(tmp1)):
        while a[tmp2[j] - 1] < 3:
            j += 1
        a[tmp2[j] - 1] -= 1
        print(tmp1[i], tmp2[j])
