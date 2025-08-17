"""
a[1] > a[2] < a[3] > a[4] < a[5]
2 1 2 1 2
有若干个下降和上升序列组成
最低点一定是取 1，先找到最低点，然后往两边扩散，不断加即可
注意相等的，注意赋值时取 max，因为最高转折点/段可能被赋值多次
不妨“缩点”，把相等的先压缩一下，这样只用考虑最高转折点被赋值两次就好了
数据范围很小，可以完全暴力地去赋值这一块
是否可以直接差分约束干了？似乎是可以的
a[i] > a[i + 1]，则 a[i] >= a[i + 1] + 1
连接 (i + 1, i, 1) 这条边
a[i] < a[i + 1]，连接 (i, i + 1, 1) 这条边
a[i] >= 1, 不妨连接 (n, i, 1) 这条边，强制一下
从 n 出发，跑最长路，其实就是所有边权取相反数，求最短路，SPFA
"""

n = int(input())
s = input()

es = []
for i in range(len(s)):
    if s[i] == '=':
        es.append((i, i + 1, 0))
        es.append((i + 1, i, 0))
    elif s[i] == 'L':
        es.append((i + 1, i, -1))
    else:
        es.append((i, i + 1, -1))
for i in range(n):
    es.append((n, i, -1))

INF = int(1e9)
q = []
d = [INF for _ in range(n + 1)]
d[n] = 0
cnt = [0 for _ in range(n + 1)]
front = 0

for rd in range(n):
    for i in range(len(es)):
        u, v, w = es[i]
        d[v] = min(d[v], d[u] + w)
for i in range(n):
    print(-d[i], end=' ')
