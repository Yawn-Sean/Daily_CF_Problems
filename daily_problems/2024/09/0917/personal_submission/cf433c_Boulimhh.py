"""
思路:这题看的羊神的题解和代码, 来浅浅复现一下 .

先统计没有变化之前的差值总和. 

再统计每个数左边的数和右边数的数, 并记录下来差值.

再遍历 n 个数, 假设是当前数变为其旁边数的中位数, 统计原来和 - 变化后的和.

将最开始的差值总和, 减去原来和- 变化后和的最大值, 即为答案.

"""
#python代码:

n, m = map(int, input().split())
a = list(map(int, input().split()))
ma = 0
c = [0] * (n + 1)
tmp = [[] for _ in range(n + 1)]

for i in range(1, m):
    t = abs(a[i] - a[i - 1])
    ma += t

    if t:
        c[a[i]] += t
        c[a[i - 1]] += t
        tmp[a[i]].append(a[i -  1])
        tmp[a[i - 1]].append(a[i])
res = 0
for i in range(1, n + 1):
    l = len(tmp[i])
    if l:
        tmp[i].sort()
        x = tmp[i][l // 2]
        res = max(res, c[i] - sum(abs(x - v) for v in tmp[i]))
print(ma - res)
