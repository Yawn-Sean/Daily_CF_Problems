s1 = input().strip()
s2 = input().strip()
ma = max(3, len(s1), len(s2))
a1 = list(map(int, list((ma - len(s1)) * '0' + s1)))
a2 = list(map(int, list((ma - len(s2)) * '0' + s2)))
for i in range(ma - 2):
    a, b = a1[i], a2[i]
    p = min(a, b)
    if abs(a - b) >= 2:
        if a > b:
            print('>')
        else:
            print('<')
        exit(0)
    a -= p
    b -= p
    a1[i + 1] += a
    a1[i + 2] += a
    a2[i + 1] += b
    a2[i + 2] += b
res1 = a1[-2] * 2 + a1[-1] * 1
res2 = a2[-2] * 2 + a2[-1] * 1
if res1 > res2:
    print('>')
elif res1 < res2:
    print('<')
else:
    print('=')
