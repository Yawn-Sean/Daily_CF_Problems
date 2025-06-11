    n, qs = ix()
    s = input()
    a = [0] * (n+2)
    for i, x in enumerate(s, 1):
        if x == ".": a[i] = 1
    t = 0
    for k, g in groupby(a):
        if k == 1:   t += len(list(g)) - 1
    for _ in range(qs):
        i, x = input().split()
        i = int(i)
        if x == ".":
            if a[i] != 1:
                a[i] = 1
                if a[i-1] == 1:t += 1
                if a[i+1] == 1:t+=1
        else:
            if a[i]:
                a[i] = 0
                if a[i - 1]: t -= 1
                if a[i + 1]: t -= 1
        print(t)
