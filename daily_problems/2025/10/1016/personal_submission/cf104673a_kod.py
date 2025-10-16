d = {}
inf = 10 ** 9
for i in range(100000, -1, -1):
    t = 1
    for j in range(i + 1):
        if t > inf: break
        d[t] = i + 1
        t = t * (i - j) // (j + 1)
q = ix()
for i in range(q):
    n = ix()
    if n in d:
        print(d[n])
    else:
        print(n + 1)
