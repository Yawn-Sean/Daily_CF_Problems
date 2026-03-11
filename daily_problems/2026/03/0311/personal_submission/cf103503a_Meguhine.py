# -*- coding: UTF-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()

if __name__ == "__main__":
    n, S = map(int, input().split())
    a = list(map(int, input().split()))

    res = 0

    def calc(X: int) -> int:
        global res
        res, s = X, X * (X + 1) // 2
        for x in a:
            if x <= X:
                res -= 1
            else:
                s += x
        return s

    l, r, opt = 0, 2 * 10**9, -1
    while l <= r:
        mid = (l + r) >> 1
        if calc(mid) >= S:
            opt, r = mid, mid - 1
        else:
            l = mid + 1

    assert opt != -1
    calc(opt)
    print(res + len(a))
