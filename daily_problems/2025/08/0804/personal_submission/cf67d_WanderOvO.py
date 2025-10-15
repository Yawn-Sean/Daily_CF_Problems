"""
假如按照入射点从左到右选，已经选了若干条两两相交的线了，如何选一条新的线？
假设前面已经选的所有线，最左射出点是 left，则新选的线的射出点必须比 left 小
按照入射点的线的 id 顺序，把对应的出射点序列构造出来，则求一个最长下降子序列就好了
"""

n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))
out_id = [0 for i in range(n + 1)]
for i in range(1, n + 1):
    out_id[b[i]] = i
in_id = [0 for i in range(n + 1)]
for i in range(1, n + 1):
    in_id[a[i]] = i

c = []
for i in range(1, n + 1):
    c.append(out_id[a[i]])
c.reverse()
c = [0] + c

tr = [0 for i in range(n + 1)]

def lowbit(x):
    return x & -x

def add(pos, x):
    while pos <= n:
        tr[pos] = max(tr[pos], x)
        pos += lowbit(pos)

def query(pos):
    res = 0
    while pos > 0:
        res = max(res, tr[pos])
        pos -= lowbit(pos)
    return res

dp = [0 for i in range(n + 1)]
res = 0
for i in range(1, n + 1):
    dp[i] = query(c[i] - 1) + 1
    add(c[i], dp[i])
    res = max(res, dp[i])
print(res)
