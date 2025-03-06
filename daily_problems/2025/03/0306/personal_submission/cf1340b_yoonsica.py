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

# print(d['0000000'][7])
# print(d['0010010'])
n, k = RII()
a = []
for _ in range(n):
    a.append(RS())

f = [[0] * (k + 1) for _ in range(n + 1)]
f[n][0] = 1
for i in range(n - 1, -1, -1):
    x = a[i]
    for j in range(k + 1):
        if x in m:
            f[i][j] = f[i + 1][j]
        for c in range(1, mn(j, 7) + 1):
            if f[i + 1][j - c] and (d[x][c] != -inf):
                f[i][j] = 1
                break

if f[0][k]:
    # 贪心从高到低构造
    ans = []
    for i, x in enumerate(a, 1):
        t, cnt = -1, 0
        for j in range(k + 1):
            if f[i][j]:
                # 有j - cnt个可以给x
                if d[x][j] > t:
                    t, cnt = d[x][j], j
        ans.append(t)
        k -= cnt
    print(''.join(map(str, ans)))
else:
    print(-1)

