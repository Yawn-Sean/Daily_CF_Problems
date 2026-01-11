'''
https://codeforces.com/gym/106298/submission/357341477
'''
# math, prime factors
def solve(n: int, la: list[int], ra: list[int]) -> list[int]:
    g = -1
    for l, r in zip(la, ra):
        if l == r:
            g = l if g < 0 else gcd(g, l)
    if g > 0:
        for p in prime_elements(g):
            if all(l + -l % p <= r for l, r in zip(la, ra)):
                return [l + -l % p for l in la]
        return []
    else:
        return [x + 1 if x & 1 else x for x in la]
