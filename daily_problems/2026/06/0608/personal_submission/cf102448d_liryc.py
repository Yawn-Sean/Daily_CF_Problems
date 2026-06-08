'''
https://codeforces.com/gym/102448/submission/377730828
Geometry
'''
def solve(n: int, x: int, y: int, a: list[list[int]]) -> float:
    ans, r = 0.0, 0.0
    da = [((x1 - x) ** 2 + (y1 - y) ** 2) ** 0.5 - r1 for x1, y1, r1 in a]
    for i in sorted(range(n), key=lambda i: da[i]):
        _, _, r1 = a[i]
        if r < da[i]:
            ans += da[i] - r
            r = da[i]
        r += r1
    return ans
