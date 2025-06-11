'''
https://codeforces.com/contest/798/submission/272234389
798C
2024/7/24 Y1
1700
math
'''

from itertools import groupby
from math import gcd

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n, a):
    if gcd(*a) > 1:
        return 0
    ans = 0
    for k, g in groupby(x & 1 for x in a):
        if k == 1:
            c = sum(1 for _ in g)
            ans += (c >> 1) + ((c & 1) << 1)
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans < 0:
        print("NO")
    else:
        print("YES")
        print(ans)