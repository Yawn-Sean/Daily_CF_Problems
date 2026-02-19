'''
2026/2/19 Y1
1000
'''
# gcd and lcm
from sys import stdin
input = lambda: stdin.readline().strip()
from math import lcm

def init():
    n, l, r, k = map(int, input().split())
    a = list(map(int, input().split()))
    return n, l, r, k, a

def solve(n: int, l: int, r: int, k: int, a: list[int]):
    if r < k or min(a) < k:
        return -1
    m = 1
    for e in a:
        m = lcm(m, e)
        if m > r:
            return -1
    # m = reduce(lcm, a) # m will be extremely large and cause TLE
    x = (r - k) // m * m + k
    return x if l <= x <= r else -1

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
