'''
https://codeforces.com/gym/104493/submission/351798742
'''
def solve(r: int, n: int, l: int) -> int:
    return pi * r * r + l * r * n + l * l / 2 / tan(pi / n) * n / 2
