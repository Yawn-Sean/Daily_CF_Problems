n = ix()
a, b = il()
t = il()
tt = [[i, x] for i , x in enumerate(t)]
if a == b:
    res = [1] * a + [2] * a
    exit(print(*res))
if a > b:
    tt.sort(key=lambda x: x[1])
    res = [0] * len(t)
    for ii, (i, x) in enumerate(tt):
        if ii < a:
            res[i] = 1
        else:
            res[i] = 2
    print(*res)
else:
    tt.sort(key=lambda x: (x[1], -x[0]))
    res = [0] * len(t)
    for ii, (i, x) in enumerate(tt):
        if ii < b:
            res[i] = 2
        else:
            res[i] = 1
    print(*res)
