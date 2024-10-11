ii = lambda: int(input())

def query(i):
    print('?', i, flush=True)
    return ii()

def answer(i):
    print('!', i, flush=True)

def solve():
    n = ii() // 2
    if n % 2 == 1:
        answer(-1)
        return
    sign = query(1) - query(1+n)
    if sign == 0:
        answer(1)
        return
    l, r = 1, 1+n
    while True:
        m = (l + r) // 2
        x = query(m) - query(m+n)
        if x < 0:
            if sign < 0:
                l = m + 1
            else:
                r = m - 1
        elif x > 0:
            if sign < 0:
                r = m - 1
            else:
                l = m + 1
        else:
            answer(m)
            return

solve()
