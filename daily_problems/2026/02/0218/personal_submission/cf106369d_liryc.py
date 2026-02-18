'''
https://codeforces.com/gym/106369/submission/363488522
'''
def solve(y: int, x: int, r: int) -> float: 
    if x < 0:
        x = -x
    if x * x * y * y > r * r * (x * x + y * y):
        return -1
    elif r >= x:
        return 0
    else:
        return (asin(y / hypot(x, y) / r * x) - atan2(y, x)) / pi * 180

