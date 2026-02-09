'''
GYM106124-D 2026.2.9 Y2 2100
'''
def solve(n: int, xa: list[int], ya: list[int]) -> float: 
    def distance(i, j):
        x1, y1 = xa[i], ya[i]
        x2, y2 = xa[j], ya[j]
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
    idx = 0
    for i in range(n):
        if distance(0, i) > distance(0, idx):
            idx = i
    sa = sorted(range(n), key=lambda x: distance(idx, x))
    ans = 0
    for i in range(1, n):
        ans += (distance(sa[i - 1], sa[i])) ** 0.5
    return ans