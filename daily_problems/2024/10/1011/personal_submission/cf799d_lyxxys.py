import bisect
import collections
import heapq
import sys
import typing
import math
input = lambda: sys.stdin.readline().strip()

def main():
    def ceil(x:int, y:int)->int:
        return (x + y - 1) // y
    a, b, h, w, n = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort(reverse = True)
    A = A[:min(34, len(A))]
    inf = 1e9
    def func(sx:int, sy:int):
        f = {}
        f[(sx, sy)] = 0
        for num in A:
            for (px, py) in list(f.keys()):
                x, y, cur = ceil(px, num), ceil(py, num), f[(px, py)]
                if (x, py) not in f:  # 对 x 操作
                    f[(x, py)] = cur+1
                if (px, y) not in f:  # 对 y 操作
                    f[(px, y)] = cur+1

        return f[(1, 1)] if (1, 1) in f else inf


    ans = min(func(ceil(a, h), ceil(b, w)), func(ceil(b, h), ceil(a, w)))

    print(ans if ans < inf else -1)
