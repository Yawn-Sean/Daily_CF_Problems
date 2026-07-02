'''
https://codeforces.com/gym/106607/submission/381000338
simple geometry
'''
def solve(n: int, pa: list[list[int]]) -> int:
    ans, c1, c2, c3 = 0, 0, 0, 0
    for x, y in pa:
        if x > y:
            ans += c2 + c3
            c1 += 1
        elif x < y:
            ans += c1 + c3
            c2 += 1
        else:
            ans += c1 + c2 + c3
            c3 += 1
    return ans
