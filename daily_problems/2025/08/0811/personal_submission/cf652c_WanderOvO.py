"""
正难则反，考虑至少包含一对给定元素的区间有多少个
枚举右端点 r，考虑有多少个左端点符合题意
我们关心所有的 y <= r 的元素，看这里面 x 的最大值 maxx，则 maxx 就是右端点为 r 时至少包含一对元素的区间数
题目给定的全排列，可以先 reid 一下，变成 1...n，然后把所有的元组也这样变换一下
用快读，排下标
"""
import sys

input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
a = list(map(int, input().split()))
mp = [0 for i in range(n + 1)]
for i in range(n):
    mp[a[i]] = i
xs = []
ys = []
for i in range(m):
    x, y = map(int, input().split())
    x = mp[x]
    y = mp[y]
    if x > y:
        x, y = y, x
    xs.append(x)
    ys.append(y)

order = [i for i in range(m)]
order = sorted(order, key=lambda i: ys[i])

maxx = -1
res = 0
pt = 0
for i in range(n):
    while pt < m and ys[order[pt]] <= i:
        maxx = max(maxx, xs[order[pt]])
        pt += 1
    res += maxx + 1

print(n * (n + 1) // 2 - res)
