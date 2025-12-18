'''
https://codeforces.com/gym/105789/submission/353946229
'''
# 模拟，分类讨论
def solve(n: int, p: int, h: int, cards: list[str]) -> int:
    nplus, nmulti, nhit = 0, 0, 0
    pa, ma = [], []
    for s in cards:
        if s[0] == '*':
            nmulti += 1
            ma.append(int(s.split()[1]))
        elif s[0] == '+':
            nplus += 1
            pa.append(int(s.split()[1]))
        else:
            nhit += 1
    if nhit == 0 or p == nplus == 0:
        return -1
    if nplus == 0 and (nmulti == 0 or all(x == 1 for x in ma)):
        t, r = divmod((h + p - 1) // p - 1, nhit)
        return t * n + r + 1
    ma.sort(reverse=True)
    pa.sort(reverse=True)
    ans = 0
    def check1(c):
        nonlocal h, n, nplus, nmulti, nhit, ma, pa
        for y in pa:
            c += y
        for x in ma:
            if x <= 1:
                break
            c *= x
            if c >= h:
                return 0
        return 0 if c * nhit >= h else c
    def check2(c, m):
        nonlocal h, n, nplus, nmulti, nhit, ma, pa
        for ihit in range(pmax(1, m - nplus - nmulti), pmin(m, nhit) + 1):
            for iplus in range(pmax(0, m - nmulti - nhit), pmin(m, nplus) + 1):
                imulti = m - ihit - iplus
                if 0 <= imulti <= nmulti:
                    d = c
                    for y in pa[:iplus]:
                        d += y
                    for x in ma[:imulti]:
                        d *= x
                    if d * ihit >= h:
                        return True
        return False
    while h:
        b = check1(p)
        if b:
            p = b
            h -= p * nhit
            ans += n
        else:
            for m in range(1, n + 1):
                if check2(p, m):
                    return ans + m
    return ans
