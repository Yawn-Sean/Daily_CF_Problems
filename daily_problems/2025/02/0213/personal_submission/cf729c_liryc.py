'''
https://codeforces.com/problemset/submission/729/305888377
'''
# calc min capacity by binary search, then choose the cheapest car

def solve(n: int, k: int, s: int, t: int, cars: list[tuple[int]], gs: list[int]) -> int:
    if s > t:
        return -1

    gs.sort()
    gs = [0] + gs + [s]

    def check(m):
        nonlocal t, gs
        ts = 0
        for a, b in pairwise(gs):
            d = b - a
            if m < d:
                return False
            ac = min(m - d, d)
            ts += 2 * d - ac
        return ts <= t
            
    minv = bisect_left(range(2 * s + 1), True, key = check)
    return min((c for c, v in cars if v >= minv), default = -1)
