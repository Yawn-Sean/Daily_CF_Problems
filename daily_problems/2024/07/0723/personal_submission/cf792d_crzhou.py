n, q = MII()
res = []

for _ in range(q):
    u = II()
    s = input()

    for c in s:
        x = u & -u # 最低位
        if c == 'L':
            if x > 1:
                u -= x // 2
        elif c == 'R':
            if x > 1:
                u += x // 2
        else:
            if x * 2 < n:
                u -= x
                u |= x * 2

    res.append(u)

print('\n'.join(map(str, res)))
