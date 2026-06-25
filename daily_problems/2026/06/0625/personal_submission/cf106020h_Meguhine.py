import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
a = array('i', map(int, input().split()))

nxt = array('i', [-1] * n)
for i in range(n - 2, -1, -1):
    nxt[i] = nxt[i + 1] if a[i + 1] == 0 else (i + 1)

pre, ans = -1, 0
for i, x in enumerate(a):
    if x == 0:
        continue
    j = nxt[i]
    if j == -1:
        break
    y = a[j]
    if x > y:
        x, y = y, x
    if x == 1 and (y == 1 or y == 2):
        l = (i + 1) if pre == -1 else (i - pre)
        r = (n - j) if nxt[j] == -1 else (nxt[j] - j)
        ans += l * r - int(i + 1 == j)
    pre = i
print(ans)


"""
设 mex 为 m, 那么至少包含 0~m-1 的数
那么 sum 至少为 m(m-1)/2
m(m-1)/2 == m  =>  m == 3
所以就两种情况:
- 任意个 0, 一个 1, 一个 2, mex = 3
- 任意个 0, 两个 1, mex = 2
"""
