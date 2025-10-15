'''
https://codeforces.com/problemset/submission/592/307608916
'''
# LCM+math
def solve(t: int, w: int, b: int) -> str:
    if w == b:
        return "1/1"
    m = lcm(w, b)
    if w > b:
        w, b = b, w
    d, v = divmod(t, m)
    c = w * d + min(v + 1, w) - 1
    g = gcd(c, t)
    return f"{c // g}/{t // g}"
