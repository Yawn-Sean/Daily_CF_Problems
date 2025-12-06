'''
GYM106241G
2025/12/6 Y1
1800
'''

import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x

def init():
    n, m = map(int, input().split())
    ne = []
    for _ in range(m):
        u, v = map(int, input().split())
        ne.append([u - 1, v - 1])
    return n, m, ne

def solve(n: int, m: int, ne: list[list[int]]) -> int:
    MOD = 998244353
    return -1

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
