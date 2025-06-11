'''
https://codeforces.com/problemset/submission/229/294618029
229C
2024/12/3 Y2
1900
math
'''
#ref
from math import comb
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    cn = [0] * n # Counter() TLE
    for _ in range(m):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        cn[u] += 1
        cn[v] += 1
    return n, cn

def solve(n: int, cn: list[int]):
    ans = sum(cn[i] * (n - 1 - cn[i]) for i in range(n))
    return comb(n, 3) - (ans >> 1)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)