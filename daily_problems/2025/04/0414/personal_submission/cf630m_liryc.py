'''
https://codeforces.com/problemset/submission/630/315527497
'''
def solve(x: int) -> int:
    x %= 360
    d = 360
    ans = -1

    for i, r in enumerate([0, 90, 180, 270]):
        v = (x - r) % 360
        v = min(v, 360 - v)
        if v < d:
            d, ans = v, i
    return ans