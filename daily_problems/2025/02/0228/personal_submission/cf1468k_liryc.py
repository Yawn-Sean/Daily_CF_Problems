'''
https://codeforces.com/problemset/submission/1468/308236928
'''
# 模拟，然后枚举所有路径上的点进行验证答案
def solve(s: str) -> list[int]:
    hs = set()
    di = {'L': (-1, 0), 'R': (1, 0), 'D': (0, -1), 'U': (0, 1)}
    x, y = 0, 0
    for c in s:
        dx, dy = di[c]
        x, y = x + dx, y + dy
        hs.add((x, y))
    for bx, by in hs:
        x, y = 0, 0
        for c in s:
            dx, dy = di[c]
            if (bx, by) != (x + dx, y + dy):
                x, y = x + dx, y + dy
        if (x, y) == (0, 0):
            return [bx, by]
    return [0, 0]
