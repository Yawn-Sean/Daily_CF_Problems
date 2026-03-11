# -*- coding: UTF-8 -*-
import sys

global outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()


def solve(_case: int) -> None:
    n, X = map(int, input().split())
    full = (1 << (n.bit_length() - 1)) - 1

    l, r, pos = 1, n, 1
    pre = 0
    cur = full
    pos_last = 0

    while True:
        mid = (l + r) >> 1
        if X == mid:
            outs[_case] = str(pre + (pos if pre != full else pos_last + 1))
            return
        pre = pre << 1 | 1
        cur >>= 1
        if X < mid:
            r = mid - 1
            pos = (pos << 1) - 1
        else:
            pos_last += mid - l - cur
            l = mid + 1
            pos <<= 1


if __name__ == "__main__":
    total_cases = int(input())
    outs = [""] * total_cases
    for _ in range(total_cases):
        solve(_)
    print(" ".join(outs))
