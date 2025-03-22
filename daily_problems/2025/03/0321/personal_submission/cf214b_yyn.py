
def main():
    n = II()
    c = defaultdict(list)
    a = LII()
    f = True
    mod = 0
    for x in a:
        c[x % 3].append(x)
        if x == 0:
            f = False
        mod = (mod + x) % 3
    if f:
        return print(-1)
    if mod == 0:
        a = []
        for row in c.values():
            a.extend(row)
        a.sort(reverse=True)
        if a[0] == 0:
            return print(0)
        for x in a:
            print(x,end='')
        return
    for i in range(3):
        c[i].sort(reverse=True)

    n,m = len(c[1]),len(c[2])
    a = c[0].copy()
    if mod == 1:
        if n != 0:
            a.extend(c[2].copy())
            a.extend(c[1][:-1])
        else:
            if m >= 2:
                a.extend(c[2][:-2])
    else:
        if m != 0:
            a.extend(c[1].copy())
            a.extend(c[2][:-1])
        else:
            if n >= 2:
                a.extend(c[1][:-2])
    a.sort(reverse=True)
    if a[0] == 0:
        return print(0)
    for x in a:
        print(x,end='')
