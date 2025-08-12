'''
https://codeforces.com/problemset/submission/126/333624963
'''
# math, iterations
def solve(t1: int, t2: int, x1: int, x2: int, t0: int) -> list[int]:
    if t1 == t2 == t0:
        return [x1, x2]
    elif t1 == t0:
        return [x1, 0]
    elif t2 == t0:
        return [0, x2]
    else:
        a1, a2 = 0, x2
        for y1 in range(1, x1 + 1):
            y2 = ((t0 - t1) * y1 + t2 - t0 - 1) // (t2 - t0)
            if y2 <= x2 and y2 * a1 <= a2 * y1:
                a1, a2 = y1, y2
        return [a1, a2]
