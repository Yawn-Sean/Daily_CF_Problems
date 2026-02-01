n, m = il()
ans = tt = - 1
for i in range(m):
    x = input()
    a, b, c = 'A', 'B', 'C'
    v = 0
    for t in x[::-1]:
        v <<= 1
        if t == b:
            v += 1
            a, c = c, a
        else:
            c, b = b, c
    if v > tt:
        ans = i
        tt = v
print(ans + 1)
