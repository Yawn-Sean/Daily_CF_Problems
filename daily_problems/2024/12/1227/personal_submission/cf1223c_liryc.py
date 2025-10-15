'''
https://codeforces.com/problemset/submission/1223/298694432
1223C
2024/12/27 Y1
1600
Binary Search
'''
# 二分求下界：取最小的n s.t. contribute(n) >= k
from bisect import bisect_left
from math import lcm
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    p = list(map(int, input().split()))
    x, a = map(int, input().split())
    y, b = map(int, input().split())
    k = int(input())
    return n, p, x, a, y, b, k

def solve(n, p, x, a, y, b, k):
    p.sort(reverse=True)
    if x < y:
        x, a, y, b = y, b, x, a
    ab = lcm(a, b)
    def check(m):
        nonlocal n, p, x, a, y, b, k, ab
        if m == 0: 
            return False
        ca, cb = m // a, m // b
        cab = m // ab
        ca, cb = ca - cab, cb - cab
        e = 0
        for r in p[:m]:
            if cab:
                e += r // 100 * (x + y)
                cab -= 1
            elif ca:
                e += r // 100 * x
                ca -= 1
            elif cb:
                e += r // 100 * y
                cb -= 1
            else:
                break
        return e >= k
    ans = bisect_left(range(n + 1), True, key=check)
    if ans == n + 1:
        ans = -1
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
