'''
https://codeforces.com/gym/106186/submission/374677080
math, number theory, include-exclude
'''

def solve(n: int, a: list[int], b: list[int]) -> int:
    f, ca, cb = [0] * (n + 1), [0] * (n + 1), [0] * (n + 1)
    ans = 0
    for y in a:
        for x in all_factors(y):
            ca[x] += 1
    for y in b:
        for x in all_factors(y):
            cb[x] += 1
    for x in range(n, 1, -1):
        f[x] = ca[x] * cb[x]
        for y in range(x + x, n + 1, x):
            f[x] -= f[y]
        if isPrime(x):
            ans += f[x]
    return ans
