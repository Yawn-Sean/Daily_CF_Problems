'''
https://codeforces.com/problemset/submission/323/298759424
323A. Black-and-White Cube
2024/12/28 Y1
1600
constructive
'''
# 奇数时无解，偶数时一圈一圈地套，例如
# bbbb
# bwwb
# bwwb
# bbbb
from itertools import repeat
import sys
input = lambda: sys.stdin.readline().strip()

def build(n):
    a = [[0] * n for _ in range(n)]
    def fill(b, e, x):
        nonlocal a
        if b < e:
            i0, i1 = b, e
            while i0 < i1:
                if i0 == b:
                    a[i0][b:e + 1] = repeat(x, e - b + 1)
                    a[i1][b:e + 1] = repeat(x, e - b + 1)
                else:
                    a[i0][b] = a[i0][e] = a[i1][b] = a[i1][e] = x
                i0, i1 = i0 + 1, i1 - 1
            fill(b + 1, e - 1, x ^ 1)
    fill(0, n - 1, 0)
    return a

def output(a, b):
    for r in a:
        print(''.join('w' if x ^ b else 'b' for x in r))

if __name__ == '__main__':
    k = int(input())
    if k & 1:
        print(-1)
    else:
        a = build(k)
        for i in range(k):
            output(a, i & 1)