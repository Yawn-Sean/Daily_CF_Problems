'''
https://codeforces.com/gym/104287/submission/356456450
'''
# math
def solve(a: int, b: int, c: int) -> int:
    return -gcd(lcm(a, b), c) % c
