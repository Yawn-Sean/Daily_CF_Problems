import sys
from math import inf
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/374/A
n,m棋盘
初始在(x, y),每次移动a, b长度，向四个方向，最少多少次可以移动到四个角落
(1, m), (n, 1), (1, 1), (n, m)

只要x和y方向的距离%2相同，可以通过上下，左右反复横跳来最终到达角落
'''
n, m, x, y, a, b = RII()
d = [(1, m), (n, 1), (1,1), (n, m)]
if (x, y) in d:
    print(0)
else:
    if a >= n or b >= m:
        print('Poor Inna and pony!')
    else:
        ans = inf
        for i, j in d:
            dx, dy = abs(x - i), abs(y - j)
            if dx % a == dy % b == 0:
                cnt1, cnt2 = dx // a, dy // b
                if cnt1 % 2 == cnt2 %2:
                    ans = mn(ans, mx(dx // a, dy // b))
        print(ans if ans < inf else 'Poor Inna and pony!')