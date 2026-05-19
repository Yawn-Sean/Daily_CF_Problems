'''
20260519 1700
'''
def solve(ax: int, ay: int, bx: int, by: int, m: int, lines: list[list[int]]) -> int:  
    def dis(x1, y1, x2, y2):
        return abs(x1 - x2) + abs(y1 - y2)
    ans = dis(ax, ay, bx, by)
    for b, k in lines:
        for x1 in [ax, (ay - b) * k]:
            y1 = k * x1 + b
            for x2 in [bx, (by - b) * k]:
                y2 = k * x2 + b
                ans = min(ans, dis(ax, ay, x1, y1) + abs(x1 - x2) + dis(x2, y2, bx, by))
    return ans