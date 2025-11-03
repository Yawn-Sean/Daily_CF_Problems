'''
https://codeforces.com/gym/106157/submission/347180987
'''
def solve(m: int, t: int) -> float:
    if t <= 3 * m: 
        return 0
    def area(d):
        nonlocal m, t
        s = (t / d - m) / 2
        return s * s / tan(pi / d) * d
    f = bisect_left(range(t // m + 1), True, key=lambda k: k > 3 and area(k) >= area(k + 1))
    return area(f)

