'''
https://codeforces.com/problemset/submission/424/286467979
CF424C
20241018 Y1
1600
bit operations
'''
# ref

from functools import reduce
from operator import xor
import sys
input = lambda: sys.stdin.readline().strip()

def pxor(x):
    if x & 3 == 0: return x
    elif x & 3 == 1: return 1
    elif x & 3 == 2: return x + 1
    else: return 0

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]):
    ans = reduce(xor, a)
    for i in range(1, n + 1):
        x = n % (2 * i)
        if x >= i: ans ^= pxor(i - 1) ^ pxor(x - i)
        else: ans ^= pxor(x)
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)