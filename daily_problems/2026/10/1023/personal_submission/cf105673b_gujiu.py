import sys, math
from decimal import Decimal, getcontext
from collections import *
from functools import cache
getcontext().prec = 2000
sys.setrecursionlimit(5000)
MOD = int(1e9+7)
INF = int(1e18)
MAXX = int(2e5+10)
input = sys.stdin.buffer.readline



def solve() -> None:
    n, k = map(int, input().split())
    ans = k
    a = [0, *map(int, input().split())]
    for i in range(1, n + 1):
        j, x, res = i, 1, k
        while j <= n:
            res += a[j]
            j += x
            x += 1
            if res < 0:
                break
            ans = max(ans, res)
    print(ans)





if __name__=="__main__":
    for _ in range(int(input())):
        solve()