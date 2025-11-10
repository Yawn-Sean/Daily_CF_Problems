'''
https://codeforces.com/gym/106179/submission/348222528
'''
def solve(n: int) -> list[int]:
    return [n << 30, n << 30 ^ n]
