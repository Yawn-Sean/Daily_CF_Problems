'''
https://codeforces.com/gym/106045/submission/352780029
'''
def solve(r: int, l: int, a: int) -> float:
    d = r * sin(a * pi / 360) * 2
    return (l * l - d * d) ** 0.5
