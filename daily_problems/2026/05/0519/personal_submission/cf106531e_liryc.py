'''
https://codeforces.com/gym/106531/submission/375209933
Math, simple geometry
'''
def solve(ax: int, ay: int, bx: int, by: int, m: int, lines: list[list[int]]) -> int:  
    ans = abs(ax - bx) + abs(ay - by)
    if ax == bx or ay == by:
        return ans
    ua, va = ay - ax, ay + ax
    ub, vb = by - bx, by + bx
    du = abs(ua - ub)
    dv = abs(va - vb)
    for k, d in lines:
        if d == 1:
            mu = abs(ua - k) + abs(ub - k)
            ans = min(ans, max(mu, mu + dv >> 1))
        else:
            mv = abs(va - k) + abs(vb - k)
            ans = min(ans, max(mv, mv + du >> 1))
    return ans
