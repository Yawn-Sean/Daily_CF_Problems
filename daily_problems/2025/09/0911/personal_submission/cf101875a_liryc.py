'''
https://codeforces.com/gym/101875/my#
'''
def solve(n: int, k: int) -> int:
    g = gcd(n, k)
    return (n - g) * k + (g - 1) * (k - 1)
