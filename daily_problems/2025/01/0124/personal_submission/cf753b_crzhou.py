pre = -1
for j in range(0, 10):
    s = str(j) + '000'
    print(s, flush=True)
    a, _ = MII()
    if pre != -1 and a != pre:
        if a > pre:
            a = j
        else:
            a = j - 1
        break
    pre = a

pre = -1
for j in range(0, 10):
    s = '0' + str(j) + '00'
    print(s, flush=True)
    b, _ = MII()
    if pre != -1 and b != pre:
        if b > pre:
            b = j
        else:
            b = j - 1
        break
    pre = b

pre = -1
for j in range(0, 10):
    s = '00' + str(j) + '0'
    print(s, flush=True)
    c, _ = MII()
    if pre != -1 and c != pre:
        if c > pre:
            c = j
        else:
            c = j - 1
        break
    pre = c

pre = -1
for j in range(0, 10):
    s = '000' + str(j)
    print(s, flush=True)
    d, _ = MII()
    if pre != -1 and d != pre:
        if d > pre:
            d = j
        else:
            d = j - 1
        break
    pre = d

print(str(a) + str(b) + str(c) + str(d))
