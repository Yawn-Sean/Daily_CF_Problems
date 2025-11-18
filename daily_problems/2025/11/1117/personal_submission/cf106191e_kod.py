def query(s, t):
    print('?', len(s), *s, len(t), *t, flush = True)
    return ix()

def answer(ans):
    print('!', ans, flush = True)

t = ix()
for i in range(t):
    n = ix()
    whole = query(list(range(1, n + 1)), list(range(1, n + 1)))
    d = [0] * n
    for i in range(1, n):
        c = [x for x in range(1, n + 1) if x != i]
        d[i - 1] = whole - query(c, c)

    d[-1] = whole * 2 - sum(d)
    if 1 in d:
        for i in range(n - 1, -1, -1):
            if d[i] == 1:
                break
        answer(i + 1)
    else:
        answer(-1)
