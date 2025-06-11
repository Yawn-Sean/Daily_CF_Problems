# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())


q = I()
ops = [LI() for _ in range(q)]

tree = [0 for i in range(60)]
mod = [1 << i for i in range(60)]
start = [1 << i for i in range(60)]


def idx(i, x):
    j = x - start[i]
    j -= tree[i]
    j %= mod[i]
    return j


def val(i, j):
    j += tree[i]
    j %= mod[i]
    x = start[i] + j
    return x


for op in ops:
    if op[0] == 1:
        x, k = op[1:]
        k = -k
        i = x.bit_length() - 1
        tree[i] += k
        tree[i] %= mod[i]
    elif op[0] == 2:
        x, k = op[1:]
        k = -k
        for i in range(x.bit_length() - 1, 60):
            tree[i] += k
            tree[i] %= mod[i]
            k *= 2
    else:
        x = op[1]
        i = x.bit_length() - 1
        j = idx(i, x)
        ans = [x]
        for i1 in range(i - 1, -1, -1):
            j //= 2
            ans.append(val(i1, j))
        print(*ans)
