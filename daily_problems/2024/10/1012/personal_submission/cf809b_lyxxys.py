import bisect
import collections
import heapq
import sys
import typing
import math
input = lambda: sys.stdin.readline().strip()

def main():

    def query(x:int, y:int) -> bool:
        print(1, x, y, flush=True)
        res = input()
        return res == "TAK"

    def find(L:int, R:int) -> int:
        l, r = L, R
        while l < r:
            mid = (l + r) // 2
            if query(mid, mid+1): r = mid
            else: l = mid + 1
        return min(l, r)

    n, k = map(int, input().split())
    x = find(1, n)
    y = find(1, x-1)
    if y == 0 or not query(y, x):
        y = find(x+1, n)

    print(2, x, y)

