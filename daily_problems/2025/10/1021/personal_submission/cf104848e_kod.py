t = ix()
res = {
    12: 48,
    15: 5055,
    18: 288,
    21: 7077,
    24: 8088,
    27: 3699,
    36: 48888,
    45: 5055555555,
    54: 222888888,
    63: 111888,
    72: 8088888888,
    81: 9099999999,
    }
for i in range(t):
    n = ix()
    if n in res:
        print(res[n])
    elif len(set(str(n))) == 1:
        print(n)
    else:
        print(-1)
