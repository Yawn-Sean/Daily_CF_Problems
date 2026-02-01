'''
https://codeforces.com/gym/104408/submission/360951667
'''
# math, greedy
def solve(x1: int, y1: int, x2: int, y2: int) -> float:
    if x1 == x2 == 0 or y1 == y2 == 0:
        return abs(y1 - y2) + abs(x1 - x2)
    a, b = pmax(abs(x1), abs(y1)), pmax(abs(x2), abs(y2))
    r = pmin(a, b)
    return 0.5 * pi * r + abs(a - b)

