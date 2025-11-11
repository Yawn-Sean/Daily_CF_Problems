times = 0
if not times:
    times = II()
for _ in range(times):
    n = II()
    p = LII()
    a, b = [], []
    for i in range(n):
        if (i < n // 2) ^ (p[i] <= n // 2):
            a += p[i],
        else:
            b += p[i],
    if a and b:
        print(2)
        print(len(a), *a)
        print(len(b), *b)
    else:
        print(1)
        print(len(a + b), *(a + b))
