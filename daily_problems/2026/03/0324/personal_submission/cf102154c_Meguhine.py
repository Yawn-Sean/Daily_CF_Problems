# -*- coding: UTF-8 -*-
import sys
from random import randint as rd

input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y


LIM = 15000
tot, outs = 0, [""] * LIM


if __name__ == "__main__":
    n = int(input())
    pos = list(map(lambda s: int(s) - 1, input().split()))

    a = [0] * n
    for i, x in enumerate(pos):
        a[x] = i

    b = [0] * n

    # l,r are 0-based-index
    def work(l: int, r: int) -> None:
        global tot, outs
        assert tot < LIM

        outs[tot] = f"{l + 1} {r + 1}"
        tot += 1

        j = l + 1
        for i in range(l, r + 1):
            b[j] = a[i]
            j += 2
            if j > r:
                j = l
        for i in range(l, r + 1):
            a[i] = b[i]
            pos[a[i]] = i

    for _ in range(300):
        l, r = rd(0, n - 1), rd(0, n - 1)
        if l == r:
            continue
        if l > r:
            l, r = r, l
        if l & 1 == r & 1:
            r -= 1
        work(l, r)

    for x in range(n - 1, -1, -1):
        while a[x] != x:
            p = pos[x]
            len = fmin(p + 1, x - p)
            work(p - len + 1, p + len)

    assert a == sorted(a)
    print(tot)
    print('\n'.join(map(lambda x: outs[x], range(tot - 1, -1, -1))))
