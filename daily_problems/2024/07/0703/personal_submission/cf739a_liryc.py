'''
https://codeforces.com/contest/739/submission/268590739
739 A
2024/7/3 Y1
1700
二分: 先猜mex为d+1，然后check能不能用0..d把数组构建出来
'''

from bisect import bisect_right
from collections import deque

def init():
    n, m = map(int, input().split())
    a = []
    for _ in range(m):
        l, r = map(int, input().split())
        a.append((r - 1, r - l))
    return n, m, a

def solve(n, m, a):
    a.sort()
    ans = [0] * n
    # if can place 0..d, return 0, else return 1
    def check(d):
        nonlocal n, a, ans
        if d == 0:
            return 0
        b = [0] * n
        dq = deque(range(d + 1), d + 1)
        i, j = 0, -1
        l0, r0 = -1, -1
        for x, y in a:
            l, r = x - y, x
            if r == r0:
                continue
            else:
                l0, r0 = l, r
            while i < l:
                if i <= j:
                    dq.append(b[i])
                    i += 1
                else:
                    i, j = l, l - 1
            while dq and j < r:
                j += 1
                b[j] = dq[0]
                dq.popleft()
            if j == r and dq:
                return 1
        ans = b
        return 0
    mex = bisect_right(range(n + 1), 0, key=check)
    return mex, ans

if __name__ == '__main__':
    args = init()
    mex, ans = solve(*args)
    print(mex)
    print(*ans)
