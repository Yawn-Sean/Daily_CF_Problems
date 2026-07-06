import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()


n, m = map(int, input().split())
t = [list(map(int, input().split())) for _ in range(n)]
o = [[0] * m for _ in range(n)]
for v, _a in zip(o, t):
    a = [x + i for i, x in enumerate(_a)]
    c = Counter()
    for i in range(m - 1, -1, -1):
        v[i] = c[a[i]]
        c[a[i]] += 1
ans = 0
for j in range(m):
    a = [t[i][j] + i for i in range(n)]
    c = Counter()
    for i in range(n - 1, -1, -1):
        ans += c[a[i]] * o[i][j]
        c[a[i]] += 1
print(ans)


"""
显然对于一对 (i, j, a, b), 最多只有 1 个 d能满足题意
我们把 d 也写进条件里:
t[i][j] == a+b + d
t[i+a][j] == b + d
t[i][j+b] == a + d
用减法来消除 d:
t[i][j] - t[i+a][j] == a
t[i][j] - t[i][j+b] == b
于是我们就成功的把 a, b 分开来了, 接下来就可以乘法原理了
进行进一步的形式化, 我们相当于在求:
对于一个数组 a, a[i] 有多少个 j 满足:
a[i] - a[j] == j - i
移项得到 a[i] + i == a[j] + j
做完啦
"""
