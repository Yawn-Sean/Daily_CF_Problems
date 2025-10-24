'''
https://codeforces.com/gym/106129/submission/345471144
'''
# simple math, counting, search

# grid: element converted to bool
def solve(h: int, w: int, grid: list[list[bool]]) -> int:
    n, k = 0, pmin(h, w) # n: number of cells value=1
    for i in range(h):
        c = 0
        for j in range(w):
            if grid[i][j]:
                n += 1
                c += 1
            else: 
                if c:
                    k = pmin(k, c)
                    c = 0
        if c:
            k = pmin(k, c)
    for j in range(w):
        c = 0
        for i in range(h):
            if grid[i][j]:
                c += 1
            else:
                if c:
                    k = pmin(k, c)
                    c = 0
        if c:
            k = pmin(k, c)
    if k == 1:
        return 1
    es, stk = [], []
    for p in range(1, k):
        if p * p > k:
            break
        d, m = divmod(k, p)
        if m == 0:
            es.append(d)
            if p != d:
                stk.append(p)
    while stk:
        es.append(stk.pop())

    vis = [[False] * w for _ in range(h)]
    for t in es:
        if t == 1:
            return 1
        if n % (t * t) == 0:
            for i in range(h):
                for j in range(w):
                    vis[i][j] = False
            nFill, ok = 0, True
            for i in range(h):
                for j in range(w):       
                    if grid[i][j] and not vis[i][j]:
                        if i + t > h or j + t > w:
                            ok = False
                            break
                        for ei in range(t):
                            for ej in range(t):
                                if vis[i + ei][j + ej] or not grid[i + ei][j + ej]:
                                    ok = False
                                    break
                                vis[i + ei][j + ej] = True
                                nFill += 1
                            if not ok:
                                break
                        if not ok:
                            break
                if not ok:
                    break
            if ok and nFill == n:
                return t