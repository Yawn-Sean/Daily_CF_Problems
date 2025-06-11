'''
https://codeforces.com/problemset/submission/442/314759888
'''
# enumerate all the combinations
def solve(n: int, a: list[str]) -> int:
    b = []
    ns = len(set(a))
    LETTERS = "RGBYW"
    for t in a:
        t1, t2 = t[0], t[1]
        i1 = LETTERS.index(t1)
        i2 = int(t2) - 1
        b.append((i1, i2))
    s1 = set(r[0] for r in b)
    s2 = set(r[1] for r in b)

    if len(s1) == 1 and len(s2) == 1:
        return 0
    elif len(s1) == 1:
        return len(s2) - 1
    elif len(s2) == 1:
        return len(s1) - 1
    elif len(s1) == n:
        return n - 1
    elif len(s2) == n:
        return n - 1

    ans = 8
    for c1 in range(1, len(s1)):
        for e1 in combinations(s1, c1):
            for c2 in range(1, len(s2)):
                for e2 in combinations(s2, c2):
                    r1, r2 = set(e1), set(e2)
                    sa = set()
                    for c, v in b:
                        t = 0
                        if c in r1:
                            t = c << 4
                        else:
                            t = 5 << 4
                        if v in r2:
                            t |= v
                        else:
                            t |= 5
                        sa.add(t)
                    if len(sa) == ns:
                        ans = min(ans, c1 + c2)
    return ans              
