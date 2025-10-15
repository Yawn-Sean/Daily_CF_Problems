'''
https://codeforces.com/problemset/submission/190/306604820
'''
# 圆心距离减去两个圆半径 / 2 or 半径差减去圆心距离 / 2
def solve(x1: int, y1: int, r1: int, x2: int, y2: int, r2: int) -> float:
    d1s = (x1 - x2) ** 2 + (y1 - y2) ** 2
    d2s = (r1 + r2) ** 2
    if d2s < d1s:
        return (d1s ** 0.5 - r1 - r2) / 2
    else:
        d3s = (r1 - r2) ** 2
        if d1s < d3s:
            return (abs(r1 - r2) - d1s ** 0.5) / 2
        else:
            return 0

