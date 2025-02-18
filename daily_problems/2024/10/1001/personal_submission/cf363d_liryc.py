'''
https://codeforces.com/contest/363/submission/283910408
363 D
2024/10/1 Y1
1800
Binary Search, Greedy
'''

from bisect import bisect_right
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m, shared = map(int, input().split())
    b = list(map(int, input().split()))
    p = list(map(int, input().split()))
    return n, m, shared, b, p

def solve(n, m, shared, b, p):
    b.sort()
    p.sort()
    def check(k: int):
        nonlocal shared, b, p
        OK, FAIL = 0, 1
        if k == 0:
            return OK
        s = shared
        for cost, money in zip(p[k - 1::-1], b[-1:-k - 1:-1]):
            if money + s < cost:
                return FAIL
            if money < cost:
                s -= cost - money
        return OK

    def calc(k):
        nonlocal shared, b, p
        buy, s = 0, shared
        for cost, money in zip(p[k - 1::-1], b[-1:-k - 1:-1]):
            if money < cost:
                s -= cost - money
                buy += money
            else:
                buy += cost
        if s:
            buy = max(0, buy - s)
        return buy
    
    r = bisect_right(range(min(n, m) + 1), 0, key = check) - 1
    s = 0
    if r:
        s = calc(r)
    return r, s

if __name__ == '__main__':
    args = init()
    r, s = solve(*args)
    print(r, s)
