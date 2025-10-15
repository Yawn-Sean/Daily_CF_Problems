'''
https://codeforces.com/problemset/submission/675/309735263
'''
# 线段树
def solve(n: int, a: list[int]) -> list[int]:
    # 离散化
    rx = random.getrandbits(30)
    sa = sorted(a)
    di = { x + rx: i for i, x in enumerate(sa) }
    a = [di[x + rx] for x in a]

    # 线段树
    min_st = [(100001, -1)] * (1 << (n.bit_length() + 1))
    max_st = [(-1, -1)] * (1 << (n.bit_length() + 1))
    def update_st(p: int, idx: int, i: int = 0, l: int = 0, r: int = n - 1):
        nonlocal min_st, max_st
        if l == r:
            min_st[i] = (p, idx)
            max_st[i] = (p, idx)
            return
        m = (l + r) // 2
        if p <= m:
            update_st(p, idx, 2 * i + 1, l, m)
        else:
            update_st(p, idx, 2 * i + 2, m + 1, r)
        min_st[i] = min(min_st[2 * i + 1], min_st[2 * i + 2])
        max_st[i] = max(max_st[2 * i + 1], max_st[2 * i + 2])
    def query_left_st(x: int) -> tuple[int, int]:
        nonlocal max_st, n
        i, l, r = 0, 0, n - 1
        p, idx = -1, -1
        while r != x - 1:
            m = (l + r) // 2
            if x - 1 <= m:
                i, r = 2 * i + 1, m
            else:
                j = 2 * i + 1
                if max_st[j][-1] != -1:
                    p, idx = max_st[j]
                i, l = 2 * i + 2, m + 1
            if max_st[i][-1] == -1:
                break
        if max_st[i][-1] != -1:
            p, idx = max_st[i]
        return p, idx
    def query_right_st(x: int) -> tuple[int, int]:
        nonlocal min_st, n
        i, l, r = 0, 0, n - 1
        p, idx = -1, -1
        while l != x + 1:
            m = (l + r) // 2
            if x + 1 <= m:
                j = 2 * i + 2
                if min_st[j][1] != -1:
                    p, idx = min_st[j]
                i, r = 2 * i + 1, m
            else:
                i, l = 2 * i + 2, m + 1
            if min_st[i][1] == -1:
                break
        if min_st[i][1] != -1:
            p, idx = min_st[i]
        return p, idx
    ans = [0] * (n - 1)
    for idx, x in enumerate(a):
        if idx:
            l, li = query_left_st(x)
            r, ri = query_right_st(x)
            if li != -1 and (ri == -1 or li > ri):
                ans[idx - 1] += sa[l]
            else:
                ans[idx - 1] += sa[r]
        update_st(x, idx)
    return ans