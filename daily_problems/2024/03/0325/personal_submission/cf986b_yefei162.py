# -*- coding: utf-8 -*-

import sys

# sys.stdin = open('./../input.txt', 'r')

input = lambda: sys.stdin.readline().rstrip('\r\n')

I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(map(int, input().split()))

n = I()
a = LI()
c = [0] * n
ans = 0


def merge_sort(b, e):
    if b == e:
        return
    mid = (b + e) // 2
    merge_sort(b, mid)
    merge_sort(mid + 1, e)
    i, j = b, mid + 1
    k = b
    while i <= mid and j <= e:
        if a[i] <= a[j]:
            c[k] = a[i]
            k += 1
            i += 1
        else:
            c[k] = a[j]
            k += 1
            j += 1
            global ans
            ans += mid - i + 1
    while i <= mid:
        c[k] = a[i]
        k += 1
        i += 1
    while j <= e:
        c[k] = a[j]
        k += 1
        j += 1
    for i in range(b, e + 1):
        a[i] = c[i]


merge_sort(0, n - 1)

if (ans - n) % 2 == 0:
    print('Petr')
else:
    print('Um_nik')
