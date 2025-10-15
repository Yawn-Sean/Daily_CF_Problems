'''
https://codeforces.com/gym/105552/submission/340132630
'''
def solve(n: int, r: int, a: list[int]) -> list[int]:
    min_d = r
    
    for A, B, C in a:
        pd = abs(C) / (A * A + B * B) ** 0.5
        min_d = pd if pd < min_d else min_d
    
    ang = acos(min_d / r)
    
    v = (ang - sin(ang) * cos(ang)) / pi
    return [v, 1 - v]
