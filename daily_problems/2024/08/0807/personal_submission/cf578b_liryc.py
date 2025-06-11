'''
https://codeforces.com/contest/578/submission/275019423
578B
2024/8/7 Y1
1700
贪心
'''

from itertools import accumulate
from operator import or_

def init():
    n, k, x = map(int, input().split())
    a = list(map(int, input().split()))
    return n, k, x, a

def solve(n, k, x, a):
    ps = list(accumulate(a, or_))
    ss = [0] * n
    ss[-1] = a[-1]
    for i in range(n - 2, -1, -1):
        ss[i] = a[i] | ss[i + 1]
    m = x ** k
    ans = 0
    for i in range(n):
        v = a[i] * m
        if i > 0: 
            v |= ps[i - 1]
        if i < n - 1:
            v |= ss[i + 1]
        ans = max(ans, v)
    return ans

# ver2 - WA
# def solve(n, k, x, a):
#     m = x ** k
#     d0, d1 = a[0], a[0] * m
#     for v in a[1:]:
#         d0, d1 = d0 | v, max(d1 | v, d0 | v * m)
#     return d1

# ver1 - WA
# def solve(n, k, x, a):
    # maxi = max(range(n), key=lambda i: a[i])
    # ans = 0
    # for i, v in enumerate(a):
    #     if i == maxi:
    #         ans |= v * x ** k
    #     else:
    #         ans |= v
    # return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
