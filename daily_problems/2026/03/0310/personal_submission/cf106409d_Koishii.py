def soviet():
    n, m = map(int,input().split())
    e = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        e[u].append(v)
        e[v].append(u)

    for b in range(1, n + 1):
        if len(e[b]) <= 1: continue
        for c in e[b]:
            for d in e[c]:
                if d != b:
                    for a in e[b]:
                        if a not in (b, c, d):
                            return (a, b, c, d)

    return (-1,)


ans = soviet()
print(*ans, sep = '\n')
