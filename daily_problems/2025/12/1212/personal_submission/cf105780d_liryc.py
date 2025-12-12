'''
https://codeforces.com/gym/105780/submission/353199808
'''
# 根据点积公式，对于向量(a, b)，与之垂直又长度相等的只有(b, -a)和(-b, a)
def solve(n: int, pa: list[list[int]]) -> int:
    hs = set()
    for i in range(n):
        x, y = pa[i]
        x, y = x << 1, y << 1
        pa[i][:] = x, y
        hs.add((x, y))
    ans = 0
    for (x1, y1), (x2, y2) in combinations(pa, 2):
        x, y = x1 + x2 >> 1, y1 + y2 >> 1
        a, b = x1 - x, y1 - y
        x3, y3, x4, y4 = x - b, y + a, x + b, y - a
        if (x3, y3) in hs and (x4, y4) in hs:
            ans += 1
    return ans >> 1
