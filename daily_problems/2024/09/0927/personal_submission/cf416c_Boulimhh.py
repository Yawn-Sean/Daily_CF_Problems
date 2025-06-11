"""
思路：将客户金额和编号，按照金额排序。 将桌子加上编号， 按照人数排序。

按照金额从小到大遍历客户，同时遍历桌子。

如果当前桌子能坐下， 就把客户编号和桌子编号加入答案。 并把桌子从序列中去掉。

贪心的得出最大的答案。
"""
#python代码：
n = int(input())
a = []
for i in range(n):
    c, p = map(int, input().split())
    a.append((p, c, i + 1))
a.sort()

k = int(input())
r = list(map(int, input().split()))
ri = []
for i in range(k):
    ri.append((r[i], i + 1))
ri.sort()

res = 0
ans = []
for i in range(n - 1, -1, -1):
    for j in range(len(ri)):
        if a[i][1] <= ri[j][0]:
            res += a[i][0]
            ans.append((a[i][2], ri[j][1]))
            ri.remove(ri[j])
            break
print(len(ans), res)
for x in ans:
    print(*x)
