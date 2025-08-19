'''
https://codeforces.com/problemset/submission/1941/334504851
'''
# (OTK) binary search 
def solve(n: int, m: int, k: int, a: list[int], ma: list[int], fa: list[int]) -> int:
    m1, m2 = 0, 0
    v1, v2 = 0, 0
    for x, y in pairwise(a):
        g = y - x
        if g > m1:
            m1, m2 = g, m1
            v1, v2 = x, y
        elif g > m2:
            m2 = g
    lb, ub = max(m2, m1 + 1 >> 1), m1
    if lb == ub:
        return lb
    ma.sort()
    fa.sort()
    def check(x):
        nonlocal lb, ub, v1, v2, ma, fa
        if x == ub:
            return True
        l, r = v2 - x, v1 + x
        i, j = 0, len(fa) - 1
        while True:
            while j >= 0 and ma[i] + fa[j] > r:
                j -= 1
            if j < 0:
                return False
            while i < len(ma) and ma[i] + fa[j] < l:
                i += 1
            if i == len(ma):
                return False
            if l <= ma[i] + fa[j] <= r:
                return True
        
    return bisect_left(range(lb, ub + 1), True, key=check) + lb
