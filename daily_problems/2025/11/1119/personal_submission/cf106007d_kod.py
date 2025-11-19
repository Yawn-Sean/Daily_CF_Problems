t = ix()
for _ in range(t):
    n = ix()
    m = []
    for i in range(n):
        m += [-1 if x == '?' else int(x) for x in input()],
    p = [-2] * n
    p[0] = -1
    que = [0]
    for x in que:
        for y in range(n):
            if m[x][y] and p[y] == -2:
                p[y] =x
                que += y,
    if len(que) == n:
        ans = []
        print('YES')
        for i in que[::-1]:
            if i:
                print(p[i] + 1, i + 1)
        print()
    else:
        print('NO')
