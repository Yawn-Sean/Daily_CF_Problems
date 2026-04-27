'''
https://codeforces.com/gym/106500/submission/372688254
'''
def solve(n: int) -> int:
    return reduce(mul, (min(i, n - i + 1) for i in range(1, n + 1)))
