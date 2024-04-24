import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from functools import reduce
from math import gcd

def solve():
    m, n = lii()
    rowxor = lii()
    colxor = lii()
    rows = reduce(int.__xor__, rowxor)
    cols = reduce(int.__xor__, colxor)
    if rows != cols:
        print('NO')
        return 

    ans = [[0] * n for _ in range(m)]
    for i, x in enumerate(rowxor):
        ans[i][0] ^= x
    for j, x in enumerate(colxor):
        ans[0][j] ^= x
    ans[0][0] ^= cols

    print('YES')
    for row in ans:
        print(*row)

solve()