'''
https://codeforces.com/gym/105628/submission/363621766
'''
# gcd and lcm
def solve(n: int, l: int, r: int, k: int, a: list[int]):
    min_a = min(a)
    if min_a <= k:
        return -1
    if l <= k <= r and min_a > k:
        return k
    m = 1
    for e in a:
        m = lcm(m, e)
        if m > r:
            return -1
    x = (r - k) // m * m + k
    return x if l <= x <= r else -1
