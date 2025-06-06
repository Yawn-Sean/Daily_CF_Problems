import sys
from collections import defaultdict
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1340/B
'''

a = ["1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"]
m = {e: i for i, e in enumerate(a)}

d = defaultdict(lambda: defaultdict(lambda: -inf))


def dfs(s, cur, i, cnt):
    if i == 7:
        d[cur][cnt] = mx(d[cur][cnt], m[s])
        return
    dfs(s, cur + s[i], i + 1, cnt)
    if s[i] == '1':
        dfs(s, cur + '0', i + 1, cnt + 1)


for x in a:
    dfs(x, '', 0, 0)

n, k = RII()
a = []
for _ in range(n):
    a.append(RS())

f = [[0] * (k + 1) for _ in range(n + 1)]
f[n][k] = 1
for i in range(n - 1, -1, -1):
    x = a[i]
    for j in range(k + 1):
        for c in range(mn(k - j, 7) + 1):
            # j + c <= k
            if f[i + 1][j + c] and (d[x][c] != -inf):
                f[i][j] = 1
                break
if f[0][0]:
    # 贪心从高到低构造
    ans = []
    j = 0
    for i, x in enumerate(a):
        t, c = -1, 0
        for cnt in range(k - j + 1):
            # j + cnt <= k
            if f[i + 1][cnt + j]:
                if d[x][cnt] > t:
                    t, c = d[x][cnt], cnt
        ans.append(t)
        j += c
    print(''.join(map(str, ans)))
else:
    print(-1)

