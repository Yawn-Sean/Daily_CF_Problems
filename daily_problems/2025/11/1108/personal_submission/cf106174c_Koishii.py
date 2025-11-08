import sys
import math
input = lambda: sys.stdin.readline().rstrip()

def f(x, k) -> int:
    ans = 0
    while k:
        w = int(math.log10(x)) + 1
        pw = pow(10, w)
        dx = min(pw - x, k)
        ans += w * dx
        k -= dx
        x = pw
    return ans

def soviet():
    n = int(input())
    k = int(input())

    l = 1
    r = 10**18
    while l < r :
        mid = l + r >> 1
        if f(mid, n) >= k : r = mid
        else: l = mid + 1

    if f(l, n) == k : print(l)
    else : print(-1)

soviet()
