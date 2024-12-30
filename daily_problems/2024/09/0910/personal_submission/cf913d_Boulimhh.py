"""
思路：先找最大的 k ， 在 k 最大情况下， 找时间加和最小的任务。

学习了一下羊神对于这种题的排序， 用 lambda 表达式来排序，很奇妙。

"""
#python 代码：
n, T = map(int, input().split())
a, t = [], []
for _ in range(n):
    x, y = map(int, input().split())
    a.append(x)
    t.append(y)
r = list(range(n))
r.sort(key = lambda x: -a[x])

k, cur = 0, 0
h = []
for i in r:
    heappush(h, -t[i])
    cur += t[i]
    if cur > T:
        cur += heappop(h)
    k = max(k, min(a[i], len(h)))
print(k)

r.sort(key=lambda x: t[x])
b = []
for i in r:
    if a[i] >= k and len(b) < k:
        b.append(i + 1)
print(len(b))
print(*b)
