'''
https://codeforces.com/gym/101875/submission/338032568
'''
def solve(n: int, k: int) -> int:
    g = gcd(n, k)
    return (n - g) * k + (g - 1) * (k - 1)
