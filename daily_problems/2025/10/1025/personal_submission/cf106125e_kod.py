n = ix()
a = [0] * n

def op(l, r):
    global a
    print(l + 2, r + 1, flush=True)
    a = il()
    p = ix()
    if p > 69: exit()

while 1:
    l = ll = -1
    r = 0
    v = 0
    vmin, vmax = 0, 0
    for i, x in enumerate(a):
        if x:
            v -= 1
        else:
            v += 1
        if v < vmin:
            vmin = v
            ll = i
        t = v - vmin
        if t > vmax:
            vmax = t
            r = i
            l = ll
    op(l,r)
