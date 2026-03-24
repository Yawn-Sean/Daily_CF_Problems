# -*- coding: UTF-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
ord_A = ord('A')


n = int(input())
m = n * 3
s = input()

cnt = [0, 0, 0]
for c in s:
    cnt[ord(c) - ord_A] += 1

# ans = 0
if min(cnt) == max(cnt):
    print(0)
    sys.exit(0)

# ans = 1
idx = sorted(range(3), key=lambda x: cnt[x])
if cnt[idx[1]] >= n:
    p, cc = idx[0], cnt.copy()
    r = -1
    for l in range(m):
        while r != m - 1 and cc[p] != n:
            r += 1
            cc[ord(s[r]) - ord_A] -= 1
            cc[p] += 1
        if min(cc) == max(cc):
            print(1)
            print(f"{l + 1} {r + 1} {chr(ord_A + p)}")
            sys.exit(0)
        cc[ord(s[l]) - ord_A] += 1
        cc[p] -= 1

# ans = 2
cc = [0, 0, 0]
for i, c in enumerate(s):
    x = ord(c) - ord_A
    cc[x] += 1
    if cc[x] == n:
        print(2)
        l = i + 1
        for p in range(3):
            if p == x:
                continue
            need = n - cc[p]
            print(f"{l + 1} {l + need} {chr(p + ord_A)}")
            l += need
        sys.exit(0)
