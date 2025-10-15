n = ix()
a = il()
q = ix()
for i in range(q):
    qq = il()
    if qq[0] == 1:
        a[qq[1] - 1] = qq[2]
    else:
        if qq[1] > 1000:
            print(1)
        elif n - qq[1] > 1000:
            print(n)
        else:
            for j in range(max(0, qq[1] - 1001), min(n, qq[1] + 999)):
                if abs(j - qq[1] + 1) ** 3 >= a[j]:
                    print(j + 1)
                    break
            else:
                print(-1)
