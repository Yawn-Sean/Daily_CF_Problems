'''
https://codeforces.com/gym/105018/submission/357719963
'''
def solve(n: int, a: list[int]) -> list[int]:
    a = a + [2] + [x ^ 1 for x in a]
    ka = prep(a)
    return ka[n + 1:]
